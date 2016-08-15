/*
 * Copyright 2010-2016 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#ifndef BX_SIMD256_REF_H_HEADER_GUARD
#define BX_SIMD256_REF_H_HEADER_GUARD

#include "simd_ni.inl"

namespace bx
{
	template<>
	BX_SIMD_FORCE_INLINE simd256_ref_t simd_ld(const void* _ptr)
	{
		const simd128_t* ptr = reinterpret_cast<const simd128_t*>(_ptr);
		simd256_ref_t result;
		result.simd128[0] = simd_ld<simd128_t>(&ptr[0]);
		result.simd128[1] = simd_ld<simd128_t>(&ptr[1]);
		return result;
	}

	template<>
	BX_SIMD_FORCE_INLINE void simd_st(void* _ptr, simd256_ref_t _a)
	{
		simd128_t* result = reinterpret_cast<simd128_t*>(_ptr);
		simd_st<simd128_t>(&result[0], _a.simd128[0]);
		simd_st<simd128_t>(&result[1], _a.simd128[1]);
	}

	template<>
	BX_SIMD_FORCE_INLINE simd256_ref_t simd_ld(float _x, float _y, float _z, float _w, float _A, float _B, float _C, float _D)
	{
		simd256_ref_t result;
		result.simd128[0] = simd_ld<simd128_t>(_x, _y, _z, _w);
		result.simd128[1] = simd_ld<simd128_t>(_A, _B, _C, _D);
		return result;
	}

	template<>
	BX_SIMD_FORCE_INLINE simd256_ref_t simd_ild(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w, uint32_t _A, uint32_t _B, uint32_t _C, uint32_t _D)
	{
		simd256_ref_t result;
		result.simd128[0] = simd_ild<simd128_t>(_x, _y, _z, _w);
		result.simd128[1] = simd_ild<simd128_t>(_A, _B, _C, _D);
		return result;
	}

} // namespace bx

#endif // BX_SIMD256_REF_H_HEADER_GUARD