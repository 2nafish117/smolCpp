#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

typedef float f32;

typedef unsigned int u32;
typedef int s32;

namespace tf
{
	struct SquareMat
	{
		f32* _data = nullptr;
		u32 _dim = 0;
	};

    void SquareMat_Create(SquareMat* m, u32 dim)
	{
		assert(m != nullptr && "[SquareMat_Create] m is null");
		m->_data = (f32*) malloc(sizeof(f32) * dim * dim);
		m->_dim = dim;
	}

	void SquareMat_Destroy(SquareMat* m)
	{
		assert(m != nullptr && "[SquareMat_Destroy] m is null");
		free((void*) m->_data);
		m->_dim = 0;
	}

	f32* SquareMat_At(SquareMat* m, u32 row, u32 col)
	{
		assert(m != nullptr && "[SquareMat_Get] m is null");
		assert(m->_data != nullptr && "[SquareMat_Get] m->_data is null");
		return &m->_data[row * m->_dim + col];
	}

	void SquareMat_Print(SquareMat* m)
	{
		assert(m != nullptr && "[SquareMat_Print] m is null");
		printf("::%u x %u\n", m->_dim, m->_dim);
		for(u32 i = 0;i < m->_dim;++i)
		{
			for(u32 j = 0;j < m->_dim;++j)
			{
				printf("%f ", m->_data[i * m->_dim + j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	static void Fill_Submatrix(SquareMat* sub, SquareMat* m, u32 exclude_col)
	{
		for(u32 i = 1;i < m->_dim;++i)
		{
			for(u32 j = 0;j < m->_dim;++j)
			{
				if(j < exclude_col)
					*SquareMat_At(sub, i - 1, j) = *SquareMat_At(m, i, j);
				if(j > exclude_col)
					*SquareMat_At(sub, i - 1, j - 1) = *SquareMat_At(m, i, j);
			}
		}
	}

	f32 SquareMat_Determinant(SquareMat* m)
	{
		assert(m != nullptr && "[SquareMat_Determinant] m is null");

		if(m->_dim == 1)
			return m->_data[0];

		SquareMat sub;
		SquareMat_Create(&sub, m->_dim - 1);

		f32 det = 0.0f;

		for(u32 i = 0;i < m->_dim;++i)
		{
			u32 exclude_col = i;
			Fill_Submatrix(&sub, m, exclude_col);

			//SquareMat_Print(&sub);

			det += m->_data[i] * (i & 1 ? -1 : 1) * SquareMat_Determinant(&sub);
			//printf("det: %f\n", det);
		}
		SquareMat_Destroy(&sub);

		return det;
	}

	void SquareMat_Fill(SquareMat* m, const f32* data, u32 len)
	{
		assert(m != nullptr && "[SquareMat_Fill] m is null");
		assert(m->_dim * m->_dim <= len && "[SquareMat_Fill] overflow filling");
		memcpy(m->_data, data, len * sizeof(f32));
	}

	// TODO: optimise with slices or views

	// struct SquareMatSlice
	// {
	// 	f32* const _data = nullptr;
	// 	u32 _dim = 0;
	// 	u32 _off_r = 0, _off_c = 0;
	// };

	// void SquareMatSlice_Create(SquareMatSlice* ms, SquareMat* m, u32 top_row, u32 top_col, u32 dim)
	// {
	// 	assert(ms != nullptr && "[SquareMatSlice_Create] ms is null");
	// 	assert(m != nullptr && "[SquareMatSlice_Create] m is null");

	// 	assert(top_row + dim <= m->_dim && "[SquareMatSlice_Create] slice goes out of bound");

	// 	ms->_data = m->_data;
	// 	ms->_dim = dim;

	// 	ms->_off_r = top_row;
	// 	ms->_off_c = top_col;
	// }

	// f32 SquareMatSlice_Get(SquareMatSlice* ms, u32 row, u32 col)
	// {
	// 	assert(ms != nullptr && "[SquareMatSlice_Get] ms is null");
	// 	assert(ms->_data != nullptr && "[SquareMatSlice_Get] ms->_data is null");
	// 	return ms->_data[(row + ms->_off_r) * ms->_dim + (col + ms->_off_c)];
	// }

	// void SquareMatSlice_Destroy(SquareMatSlice* ms)
	// {
	// 	assert(ms != nullptr && "[SquareMatSlice_Create] ms is null");

	// 	ms->_data = nullptr;
	// 	ms->_dim = 0;
	// 	ms->off_r = 0;
	// 	ms->off_c = 0;
	// }
}