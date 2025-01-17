#include "stdafx.h"

void CRenderTarget::phase_chrom_aberration()
{
	u32 Offset = 0;
	float d_Z = EPS_S;
	float d_W = 1.0f;
	u32	C = color_rgba(0, 0, 0, 255);

	float EffectIntensity = g_pGamePersistent->GetActorIntoxication();
	clamp(EffectIntensity, 0.0f, 1.0f);

	const float w = float(Device.dwWidth);
	const float h = float(Device.dwHeight);

	// Half-pixel offset (DX9 only)
	Fvector2 p0, p1;

#ifdef USE_DX11
	p0.set(0.0f, 0.0f);
	p1.set(1.0f, 1.0f);
#else
	p0.set(0.5f / w, 0.5f / h);
	p1.set((w + 0.5f) / w, (h + 0.5f) / h);
#endif
	// Pass 0

#ifdef USE_DX11
	ref_rt dest_rt = RImplementation.o.dx10_msaa ? rt_Generic : rt_Color;
	u_setrt(dest_rt, 0, 0, HW.pBaseZB);
#else
	u_setrt(rt_Generic_0, 0, 0, HW.pBaseZB);
#endif

	RCache.set_Stencil(FALSE);
	RCache.set_CullMode(CULL_NONE);

	// Fill vertex buffer
	FVF::TL* pv = (FVF::TL*)RCache.Vertex.Lock(4, g_combine->vb_stride, Offset);
	pv->set(0, h, d_Z, d_W, C, p0.x, p1.y); pv++;
	pv->set(0, 0, d_Z, d_W, C, p0.x, p0.y); pv++;
	pv->set(w, h, d_Z, d_W, C, p1.x, p1.y); pv++;
	pv->set(w, 0, d_Z, d_W, C, p1.x, p0.y); pv++;
	RCache.Vertex.Unlock(4, g_combine->vb_stride);

	// Draw COLOR
	RCache.set_Element(s_chromatic_aberration->E[0]);
	RCache.set_c("chromatic_aberration_params", EffectIntensity, 0, 0, 0);
	RCache.set_Geometry(g_combine);
	RCache.Render(D3DPT_TRIANGLELIST, Offset, 0, 4, 0, 2);

#ifdef USE_DX11
	HW.pContext->CopyResource(rt_Generic_0->pTexture->surface_get(), dest_rt->pTexture->surface_get());
#endif
}