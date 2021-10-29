#pragma once

//#include <intrin.h>
#include <math.h>
#include "Defines.hpp"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define CLAMP(value, min, max) (MAX(MIN(value,max),min))
#define SHUFFLE(z, y, x, w)  (((z&3)<<6)|((y&3)<<4)|((x&3)<<2)|(w&3))

#define FROUND_TO_NEG_INF 1
#define FROUND_TO_POS_INF 2


namespace SWGL {

	typedef struct
	{
    	float a[4];
	} QFloat;

	typedef struct
    {
    	int a[4];
    } QInt;

    namespace SIMD {


        INLINED int float2int(float f)
        {
            union { int x; float y; } u;
            u.y = f;
            return u.x;
        }
        INLINED float int2float(int x)
        {
            union { int x; float y; } u;
            u.x = x;
            return u.y;
        }

        INLINED QFloat shuffle_ps(QFloat a, QFloat b, unsigned int imm8)
        {
          QFloat dst;
          dst.a[0] = a.a[imm8&3];
          dst.a[1] = a.a[(imm8>>2)&3];
          dst.a[2] = b.a[(imm8>>4)&3];
          dst.a[3] = b.a[(imm8>>6)&3];
          return dst;
        }

        INLINED QInt castps_si128(QFloat a)
        {
          union { QFloat f; QInt i; } u;
          u.f = a;
          return u.i;
        }
        INLINED QFloat castsi128_ps(QInt a)
        {
          union { QFloat f; QInt i; } u;
          u.i = a;
          return u.f;
        }
        INLINED float cvtss_f32(QFloat a)
        {
          return a.a[0];
        }

        INLINED int extract_epi32(QInt a, unsigned int imm8)
        {
          return a.a[imm8 & 3];
        }

        INLINED int cvtsi128_si32(QInt a)
        {
          return a.a[0];
        }

        INLINED QInt set1_epi32(int a)
        {
          QInt dst;
          dst.a[0] = a;
          dst.a[1] = a;
          dst.a[2] = a;
          dst.a[3] = a;
          return dst;
        }
        INLINED int testz_si128(QInt a, QInt b)
        {
          if((a.a[0] & b.a[0]) == 0 && (a.a[1] & b.a[1]) == 0 && (a.a[2] & b.a[2]) == 0 && (a.a[3] & b.a[3]) == 0)
            return 1;
          return 0;
        }
        INLINED int testc_si128(QInt a, QInt b)
        {
          if((~a.a[0] & b.a[0]) == 0 && (~a.a[1] & b.a[1]) == 0 && (~a.a[2] & b.a[2]) == 0 && (~a.a[3] & b.a[3]) == 0)
            return 1;
          return 0;
        }
        INLINED QInt load_si128(QInt * mem)
        {
          QInt dst;
          dst.a[0] = mem->a[0];
          dst.a[1] = mem->a[1];
          dst.a[2] = mem->a[2];
          dst.a[3] = mem->a[3];
          return dst;
        }
        INLINED void store_si128(QInt * mem, QInt a)
        {
          mem->a[0] = a.a[0];
          mem->a[1] = a.a[1];
          mem->a[2] = a.a[2];
          mem->a[3] = a.a[3];
        }

        INLINED QInt set_epi32(int a3,int a2,int a1,int a0)
        {
          QInt dst;
          dst.a[0] = a0;
          dst.a[1] = a1;
          dst.a[2] = a2;
          dst.a[3] = a3;
          return dst;
        }

        INLINED QFloat set1_ps(float a)
        {
          QFloat dst;
          dst.a[0] = a;
          dst.a[1] = a;
          dst.a[2] = a;
          dst.a[3] = a;
          return dst;
        }

        INLINED QInt cmpgt_epi32(QInt a, QInt b)
        {
          a.a[0] = a.a[0] > b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] > b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] > b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] > b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QInt cmplt_epi32(QInt a, QInt b)
        {
          a.a[0] = a.a[0] < b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] < b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] < b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] < b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QInt cmpeq_epi32(QInt a, QInt b)
        {
          a.a[0] = a.a[0] == b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] == b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] == b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] == b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QInt cmpneq_epi32(QInt a, QInt b)
        {
          a.a[0] = a.a[0] != b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] != b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] != b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] != b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QFloat cmpgt_ps(QFloat a, QFloat b)
        {
          a.a[0] = a.a[0] > b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] > b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] > b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] > b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QFloat cmpge_ps(QFloat a, QFloat b)
        {
          a.a[0] = a.a[0] >= b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] >= b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] >= b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] >= b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QFloat cmplt_ps(QFloat a, QFloat b)
        {
          a.a[0] = a.a[0] < b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] < b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] < b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] < b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QFloat cmple_ps(QFloat a, QFloat b)
        {
          a.a[0] = a.a[0] <= b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] <= b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] <= b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] <= b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QFloat cmpeq_ps(QFloat a, QFloat b)
        {
          a.a[0] = a.a[0] == b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] == b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] == b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] == b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QFloat cmpneq_ps(QFloat a, QFloat b)
        {
          a.a[0] = a.a[0] != b.a[0] ? 1 : 0;
          a.a[1] = a.a[1] != b.a[1] ? 1 : 0;
          a.a[2] = a.a[2] != b.a[2] ? 1 : 0;
          a.a[3] = a.a[3] != b.a[3] ? 1 : 0;
          return a;
        }

        INLINED QInt setzero_si128()
        {
          QInt dst;
          dst.a[0] = 0;
          dst.a[1] = 0;
          dst.a[2] = 0;
          dst.a[3] = 0;
          return dst;
        }

        INLINED QFloat setzero_ps()
        {
          QFloat dst;
          dst.a[0] = 0.0f;
          dst.a[1] = 0.0f;
          dst.a[2] = 0.0f;
          dst.a[3] = 0.0f;
          return dst;
        }

        INLINED QFloat set_ps(float a3,float a2,float a1,float a0)
        {
          QFloat dst;
          dst.a[0] = a0;
          dst.a[1] = a1;
          dst.a[2] = a2;
          dst.a[3] = a3;
          return dst;
        }



        INLINED QFloat blendv_ps(QFloat a, QFloat b, QFloat mask) {

        	if(float2int(mask.a[0]) & 0x80000000) b.a[0] = a.a[0];
        	if(float2int(mask.a[1]) & 0x80000000) b.a[1] = a.a[1];
        	if(float2int(mask.a[2]) & 0x80000000) b.a[2] = a.a[2];
        	if(float2int(mask.a[3]) & 0x80000000) b.a[3] = a.a[3];
        	//((QInt*)&mask)->a[3] & 0x80000000
	        return b;
        }

        INLINED QInt blendv_ps(QInt a, QInt b, QInt mask) {

        	if(mask.a[0] & 0x80000000) b.a[0] = a.a[0];
        	if(mask.a[1] & 0x80000000) b.a[1] = a.a[1];
        	if(mask.a[2] & 0x80000000) b.a[2] = a.a[2];
        	if(mask.a[3] & 0x80000000) b.a[3] = a.a[3];
	        return b;
        }

    	INLINED QInt and_si128(QInt a, QInt b)
    	{
    		a.a[0] &= b.a[0];
    		a.a[1] &= b.a[1];
    		a.a[2] &= b.a[2];
    		a.a[3] &= b.a[3];
    		return a;
    	}

    	INLINED QInt or_si128(QInt a, QInt b)
    	{
        a.a[0] |= b.a[0];
        a.a[1] |= b.a[1];
        a.a[2] |= b.a[2];
        a.a[3] |= b.a[3];
        return a;
    	}

    	INLINED QInt andnot_si128(QInt a, QInt b)
    	{
    		a.a[0] = ~a.a[0] & b.a[0];
    		a.a[1] = ~a.a[1] & b.a[1];
    		a.a[2] = ~a.a[2] & b.a[2];
    		a.a[3] = ~a.a[3] & b.a[3];
    		return a;
    	}

    	INLINED QInt mullo_epi32(QInt a, QInt b)
    	{
        a.a[0] *= b.a[0];
        a.a[1] *= b.a[1];
        a.a[2] *= b.a[2];
        a.a[3] *= b.a[3];
        return a;
    	}

    	INLINED QInt add_epi32(QInt a, QInt b)
    	{
        a.a[0] += b.a[0];
        a.a[1] += b.a[1];
        a.a[2] += b.a[2];
        a.a[3] += b.a[3];
        /*
    	  __asm volatile
    	  (
            "add %0, %8, %4 \n"
            "add %1, %9, %5 \n"
            "add %2, %10, %6 \n"
            "add %3, %11, %7 \n"
    	      : "=r"(a.a[0]), "=r"(a.a[1]), "=r"(a.a[2]), "=r"(a.a[3])
    	      : "r"(b.a[0]), "r"(b.a[1]), "r"(b.a[2]), "r"(b.a[3]),
            "r"(a.a[0]), "r"(a.a[1]), "r"(a.a[2]), "r"(a.a[3])
    	  );
        */
        return a;
    	}

    	INLINED QInt sub_epi32(QInt a, QInt b)
    	{
        a.a[0] -= b.a[0];
        a.a[1] -= b.a[1];
        a.a[2] -= b.a[2];
        a.a[3] -= b.a[3];
        return a;
    	}

    	INLINED QFloat mul_ps(QFloat a, QFloat b)
    	{
        a.a[0] *= b.a[0];
        a.a[1] *= b.a[1];
        a.a[2] *= b.a[2];
        a.a[3] *= b.a[3];
        return a;
    	}

    	INLINED QFloat div_ps(QFloat a, QFloat b)
    	{
        a.a[0] /= b.a[0];
        a.a[1] /= b.a[1];
        a.a[2] /= b.a[2];
        a.a[3] /= b.a[3];
        return a;
    	}

    	INLINED QFloat add_ps(QFloat a, QFloat b)
    	{
        a.a[0] += b.a[0];
        a.a[1] += b.a[1];
        a.a[2] += b.a[2];
        a.a[3] += b.a[3];
        return a;
    	}

    	INLINED QFloat sub_ps(QFloat a, QFloat b)
    	{
        a.a[0] -= b.a[0];
        a.a[1] -= b.a[1];
        a.a[2] -= b.a[2];
        a.a[3] -= b.a[3];
        return a;
    	}

    	//Truncated???? Don't know the actual difference :/ truncf
    	INLINED QInt cvttps_epi32(QFloat a) //Convert_FP32_To_Int32_Truncate
    	{
    	  QInt dst;
    		dst.a[0] = truncf(a.a[0]);
    		dst.a[1] = truncf(a.a[1]);
    		dst.a[2] = truncf(a.a[2]);
    		dst.a[3] = truncf(a.a[3]);
    		return dst;
    	}
    	//Not truncated???? Don't know the actual difference :/ rintf or roundf
    	INLINED QInt cvtps_epi32(QFloat a) //Convert_FP32_To_Int32
    	{
        QInt dst;
        dst.a[0] = roundf(a.a[0]);
        dst.a[1] = roundf(a.a[1]);
        dst.a[2] = roundf(a.a[2]);
        dst.a[3] = roundf(a.a[3]);
        return dst;
    	}

    	INLINED QFloat cvtepi32_ps(QInt a) //Convert_Int32_To_FP32
    	{
    		QFloat dst;
    		dst.a[0] = (float)a.a[0];
    		dst.a[1] = (float)a.a[1];
    		dst.a[2] = (float)a.a[2];
    		dst.a[3] = (float)a.a[3];
    		return dst;
    	}
    	INLINED QInt slli_epi32(QInt a, int imm8)
    	{
    		a.a[0] <<= imm8;
    		a.a[1] <<= imm8;
    		a.a[2] <<= imm8;
    		a.a[3] <<= imm8;
    		return a;
    	}
    	INLINED QInt srli_epi32(QInt a, int imm8)
    	{
        a.a[0] >>= imm8;
        a.a[1] >>= imm8;
        a.a[2] >>= imm8;
        a.a[3] >>= imm8;
        return a;
    	}
    	INLINED QFloat min_ps(QFloat a, QFloat b)
    	{
    		a.a[0] = MIN(a.a[0],b.a[0]);
    		a.a[1] = MIN(a.a[1],b.a[1]);
    		a.a[2] = MIN(a.a[2],b.a[2]);
    		a.a[3] = MIN(a.a[3],b.a[3]);
    		return a;
    	}
    	INLINED QFloat max_ps(QFloat a, QFloat b)
    	{
    		a.a[0] = MAX(a.a[0],b.a[0]);
    		a.a[1] = MAX(a.a[1],b.a[1]);
    		a.a[2] = MAX(a.a[2],b.a[2]);
    		a.a[3] = MAX(a.a[3],b.a[3]);
    		return a;
    	}
    	INLINED QInt min_epi32(QInt a, QInt b)
    	{
    		a.a[0] = MIN(a.a[0],b.a[0]);
    		a.a[1] = MIN(a.a[1],b.a[1]);
    		a.a[2] = MIN(a.a[2],b.a[2]);
    		a.a[3] = MIN(a.a[3],b.a[3]);
    		return a;
    	}
    	INLINED QInt max_epi32(QInt a, QInt b)
    	{
    		a.a[0] = MAX(a.a[0],b.a[0]);
    		a.a[1] = MAX(a.a[1],b.a[1]);
    		a.a[2] = MAX(a.a[2],b.a[2]);
    		a.a[3] = MAX(a.a[3],b.a[3]);
    		return a;
    	}

    	//ORIGINAL--------------------

        template<int idx>
        INLINED float extract(QFloat value) {

            return cvtss_f32(shuffle_ps((value), (value), SHUFFLE(0, 0, 0, idx)));
        }

        template<>
        INLINED float extract<0>(QFloat value) {

            return cvtss_f32(value);
        }

        template<int idx>
        INLINED int extract(QInt value) {

            return extract_epi32(value, idx);
        }

        template<>
        INLINED int extract<0>(QInt value) {

            return cvtsi128_si32(value);
        }

        INLINED float negate_number(float f)
        {
            //union { int x; float y; } u;
            //u.y = f;
            //u.x ^= 0x80000000;
            //return u.y;
            return -f;
        }


        INLINED float absolute_number(float f)
        {
            //union { int x; float y; } u;
            //u.y = f;
            //u.x &= ~0x80000000;
            //return u.y;
          return f > 0.0f ? f : -f;
        }

        INLINED QFloat absolute(QFloat value) {

            value.a[0] = absolute_number(value.a[0]);
            value.a[1] = absolute_number(value.a[1]);
            value.a[2] = absolute_number(value.a[2]);
            value.a[3] = absolute_number(value.a[3]);
            return value;
        }

        INLINED QFloat negate(QFloat value) {

            value.a[0] = negate_number(value.a[0]);
            value.a[1] = negate_number(value.a[1]);
            value.a[2] = negate_number(value.a[2]);
            value.a[3] = negate_number(value.a[3]);
            return value;
        }

        /*
        INLINED QFloat absolute(QFloat value) {

            __asm(
                "vldr.f32 s0, %4 \n"
                "vldr.f32 s1, %5 \n"
                "vldr.f32 s2, %6 \n"
                "vldr.f32 s3, %7 \n"
                "vabs.f32 s0, s0 \n"
                "vabs.f32 s1, s1 \n"
                "vabs.f32 s2, s2 \n"
                "vabs.f32 s3, s3 \n"
                "vstr.f32 s0, %0 \n"
                "vstr.f32 s1, %1 \n"
                "vstr.f32 s2, %2 \n"
                "vstr.f32 s3, %3 \n"
                : "=m" (value.a[0]), "=m" (value.a[1]), "=m" (value.a[2]), "=m" (value.a[3])
                : "m" (value.a[0]), "m" (value.a[1]), "m" (value.a[2]), "m" (value.a[3]));
            return value;
        }

        INLINED QFloat negate(QFloat value) {

            __asm(
                "vldr.f32 s0, %4 \n"
                "vldr.f32 s1, %5 \n"
                "vldr.f32 s2, %6 \n"
                "vldr.f32 s3, %7 \n"
                "vneg.f32 s0, s0 \n"
                "vneg.f32 s1, s1 \n"
                "vneg.f32 s2, s2 \n"
                "vneg.f32 s3, s3 \n"
                "vstr.f32 s0, %0 \n"
                "vstr.f32 s1, %1 \n"
                "vstr.f32 s2, %2 \n"
                "vstr.f32 s3, %3 \n"
                : "=m" (value.a[0]), "=m" (value.a[1]), "=m" (value.a[2]), "=m" (value.a[3])
                : "m" (value.a[0]), "m" (value.a[1]), "m" (value.a[2]), "m" (value.a[3]));
            return value;
        }
        */

        INLINED QFloat clamp(QFloat value, QFloat min, QFloat max) {
          value.a[0] = CLAMP(value.a[0], min.a[0], max.a[0]);
          value.a[1] = CLAMP(value.a[1], min.a[1], max.a[1]);
          value.a[2] = CLAMP(value.a[2], min.a[2], max.a[2]);
          value.a[3] = CLAMP(value.a[3], min.a[3], max.a[3]);
        	return value;
        }

        INLINED QInt clamp(QInt value, QInt min, QInt max) {
        	value.a[0] = CLAMP(value.a[0], min.a[0], max.a[0]);
        	value.a[1] = CLAMP(value.a[1], min.a[1], max.a[1]);
        	value.a[2] = CLAMP(value.a[2], min.a[2], max.a[2]);
        	value.a[3] = CLAMP(value.a[3], min.a[3], max.a[3]);
        	return value;
        }

        INLINED QFloat clamp01(QFloat value) {

          value.a[0] = CLAMP(value.a[0], 0.0f, 1.0f);
          value.a[1] = CLAMP(value.a[1], 0.0f, 1.0f);
          value.a[2] = CLAMP(value.a[2], 0.0f, 1.0f);
          value.a[3] = CLAMP(value.a[3], 0.0f, 1.0f);
        	return value;
        }

        INLINED QFloat blend(QFloat valueA, QFloat valueB, QFloat mask) {

            return blendv_ps(valueA, valueB, mask);
        }

        INLINED QInt blend(QInt valueA, QInt valueB, QInt mask) {

            return blendv_ps(valueA, valueB, mask);
        }

        INLINED QInt mask(QInt valueA, QInt valueB, QInt mask) {

            return or_si128(and_si128(mask, valueA), andnot_si128(mask, valueB));
        }

        INLINED QInt multiplyAdd(QInt valueA, QInt valueB, QInt valueC) {

            return add_epi32(mullo_epi32(valueA, valueB), valueC);
        }

        INLINED QFloat multiplyAdd(QFloat valueA, QFloat valueB, QFloat valueC) {

            return add_ps(mul_ps(valueA, valueB), valueC);
        }

        INLINED QInt multiplySub(QInt valueA, QInt valueB, QInt valueC) {

            return sub_epi32(mullo_epi32(valueA, valueB), valueC);
        }

        INLINED QFloat multiplySub(QFloat valueA, QFloat valueB, QFloat valueC) {

            return sub_ps(mul_ps(valueA, valueB), valueC);
        }

        INLINED QFloat lerp(QFloat t, QFloat valueA, QFloat valueB) {

            return multiplyAdd(t, sub_ps(valueB, valueA), valueA);
        }

        INLINED QInt gather(const int *base, QInt index) {
            return set_epi32(

                base[extract<3>(index)],
                base[extract<2>(index)],
                base[extract<1>(index)],
                base[extract<0>(index)]
            );
        }

        INLINED QFloat floor(QFloat a) {

          a.a[0] = floorf(a.a[0]);
          a.a[1] = floorf(a.a[1]);
          a.a[2] = floorf(a.a[2]);
          a.a[3] = floorf(a.a[3]);
          return a;
        }

        INLINED QFloat ceil(QFloat a) {

          a.a[0] = ceilf(a.a[0]);
          a.a[1] = ceilf(a.a[1]);
          a.a[2] = ceilf(a.a[2]);
          a.a[3] = ceilf(a.a[3]);
          return a;
        }

        INLINED QFloat dot3(QFloat x1, QFloat x2, QFloat y1, QFloat y2, QFloat z1, QFloat z2) {

            const QFloat half = set1_ps(0.5f);
            const QFloat four = set1_ps(4.0f);
            
            x1 = sub_ps(x1, half);
            x2 = sub_ps(x2, half);
            y1 = sub_ps(y1, half);
            y2 = sub_ps(y2, half);
            z1 = sub_ps(z1, half);
            z2 = sub_ps(z2, half);

            QFloat d1 = mul_ps(x1, x2);
            QFloat d2 = mul_ps(y1, y2);
            QFloat d3 = mul_ps(z1, z2);

            return mul_ps(four, add_ps(add_ps(d1, d2), d3));
        }
    }
}
