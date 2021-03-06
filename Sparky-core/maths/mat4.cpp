#include "mat4.h"
#include <string>
#include "quaternion.h"
namespace sparky {
	namespace maths {


		float det(int n, float *aa)
		{
			if (n == 1)
				return aa[0];
			float *bb = new float[(n - 1)*(n - 1)];//创建n-1阶的代数余子式阵bb    
			int mov = 0;//判断行是否移动   
			float sum = 0.0;//sum为行列式的值  
			for (int arow = 0; arow < n; arow++) // a的行数把矩阵a(nn)赋值到b(n-1)  
			{
				for (int brow = 0; brow < n - 1; brow++)//把aa阵第一列各元素的代数余子式存到bb  
				{
					mov = arow > brow ? 0 : 1; //bb中小于arow的行，同行赋值，等于的错过，大于的加一  
					for (int j = 0; j < n - 1; j++)  //从aa的第二列赋值到第n列  
					{
						bb[brow*(n - 1) + j] = aa[(brow + mov)*n + j + 1];
					}
				}
				int flag = (arow % 2 == 0 ? 1 : -1);//因为列数为0，所以行数是偶数时候，代数余子式为1.  
				sum += flag * aa[arow*n] * det(n - 1, bb);//aa第一列各元素与其代数余子式积的和即为行列式
			}
			delete[]bb;
			return sum;
		}

		float* inverse(int n, float *aa, float* result)
		{
			float det_aa = det(n, aa);
			//cout << "输入矩阵的行列式：" << det_aa << endl;
			if (det_aa == 0)
			{
				printf("行列式为0 ，不能计算逆矩阵。\n");
				return 0;
			}
			float *adjoint = new float[n*n];
			float *bb = new float[(n - 1)*(n - 1)];//创建n-1阶的代数余子式阵bb   

			int pi, pj, q;
			for (int ai = 0; ai < n; ai++) // a的行数把矩阵a(nn)赋值到b(n-1)  
			{
				for (int aj = 0; aj < n; aj++)
				{
					for (int bi = 0; bi < n - 1; bi++)//把元素aa[ai][0]代数余子式存到bb[][]  
					{
						for (int bj = 0; bj < n - 1; bj++)//把元素aa[ai][0]代数余子式存到bb[][]  
						{
							if (ai > bi)    //ai行的代数余子式是：小于ai的行，aa与bb阵，同行赋值  
								pi = 0;
							else
								pi = 1;     //大于等于ai的行，取aa阵的ai+1行赋值给阵bb的bi行  
							if (aj > bj)    //ai行的代数余子式是：小于ai的行，aa与bb阵，同行赋值  
								pj = 0;
							else
								pj = 1;     //大于等于ai的行，取aa阵的ai+1行赋值给阵bb的bi行  

							bb[bi*(n - 1) + bj] = aa[(bi + pi)*n + bj + pj];
						}
					}
					if ((ai + aj) % 2 == 0)  q = 1;//因为列数为0，所以行数是偶数时候，代数余子式为-1.  
					else  q = (-1);
					adjoint[ai*n + aj] = q * det(n - 1, bb);
				}
			}
			for (int i = 0; i < n; i++)//adjoint 转置
			{
				for (int j = 0; j < i; j++)
				{
					float tem = adjoint[i*n + j];
					adjoint[i*n + j] = adjoint[j*n + i];
					adjoint[j*n + i] = tem;
				}
			}
	
			for (int i = 0; i < n; i++) //打印逆矩阵  
			{
				for (int j = 0; j < n; j++)
				{
					result[i*n + j] = adjoint[i*n + j] / det_aa;

				}
			}
			delete[]adjoint;
			delete[]bb;
		}

		float mat4::Det()
		{
			return det(4.0f, elements);
		}

		mat4 mat4::Inverse()
		{
			mat4 mat;
 
			inverse(4, elements, mat.elements);
			return mat;
		}
		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0;
			}
		}

		mat4::mat4(float diagnal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0;
			}

			elements[0 + 0 * 4] = diagnal;
			elements[1 + 1 * 4] = diagnal;
			elements[2 + 2 * 4] = diagnal;
			elements[3 + 3 * 4] = diagnal;
		}


		mat4::mat4(const mat4& other)
		{
			for (int i=0;i<16;i++)
			{
				elements[i] = other.elements[i];;
			}
		}

		mat4::mat4(const mat4&& other)
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = other.elements[i];;
			}
		}


		mat4 mat4::identity()
		{
			return mat4(1);
		}
		mat4& mat4::operator = (const mat4& other)
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = other.elements[i];;
			}
			return *this;
		}
		mat4& mat4::multiply(const mat4& others)
		{
			/*mat4 result;
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					for (int e = 0; e < 4; e++)
					{
						result.elements[4*x+y] = elements[4 * e + y] * others.elements[x+4*e];
					}
				
					
				}
					
			}
			memcpy(&elements, &(result.elements), 16 * 4);
			return *this;*/


			float data[16];
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						/*sum += elements[e + row * 4] * others.elements[col + e * 4];*/
						sum += elements[e * 4 + col] * others.elements[row * 4 + e ];
					}
					data[col + row * 4] = sum;
				}
			}
			memcpy(elements, data, 4 * 4 * sizeof(float));
			return *this;
		}


		
		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(1.0f);

			float q = 1.0f / tan(3.14*(0.5f * fov) / 180.0);
			float a = q / aspectRatio;

			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[2 + 3 * 4] = -1.0f;
			result.elements[3 + 2 * 4] = c;

			return result;
		}

		Quaternion* mat4::GetRotation()
		{ 
			Quaternion *result = new Quaternion(); 
			return result; 
		}

		mat4 mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);

			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[3 + 0 * 4] = (left + right) / (left - right);
			result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
			result.elements[3 + 2 * 4] = (far + near) / (far - near);

			return result;
		}


		mat4 mat4::LookAt(const float3& camera, const float3& object, const float3& up)
		{
			mat4 result = identity();
			float3 f = (object-camera).Normalize();
			float3 s = f.Cross(up.Normalize());
			float3 u = s.Cross(f);

			result.elements[0 + 0 * 4] = s.x;
			result.elements[0 + 1 * 4] = s.y;
			result.elements[0 + 2 * 4] = s.z;

			result.elements[1 + 0 * 4] = u.x;
			result.elements[1 + 1 * 4] = u.y;
			result.elements[1 + 2 * 4] = u.z;

			result.elements[2 + 0 * 4] = -f.x;
			result.elements[2 + 1 * 4] = -f.y;
			result.elements[2 + 2 * 4] = -f.z;

			return result * Translate(float3(-camera.x, -camera.y, -camera.z));
		}

		mat4 mat4::rotation(class Quaternion& q)
		{
			mat4 result(0.0f);

			result.elements[0] = 2 * q.x*q.x + 2 * q.w*q.w - 1;
			result.elements[4] = 2 * q.x*q.y - 2 * q.w*q.z;
			result.elements[8] = 2 * q.x*q.z + 2 * q.w*q.y;
			//result.elements[3] = 0;
			result.elements[1] = 2 * q.x*q.y + 2 * q.w*q.z;
			result.elements[5] = 2 * q.y*q.y + 2 * q.w*q.w - 1;
			result.elements[9] = 2 * q.y*q.z - 2 * q.w*q.x;
			//result.elements[7] = 0;
			result.elements[2] = 2 * q.x*q.z - 2 * q.w*q.y;
			result.elements[6] = 2 * q.y*q.z + 2 * q.w*q.x;
			result.elements[10] = 2 * q.z*q.z + 2 * q.w*q.w - 1;
			//result.elements[11] = 0;
			result.elements[15] = 1;
			return result;
		}
		mat4 mat4::Translate(const float3& translation)
		{
			mat4 result(0.0f);

			result.elements[0] = 1;
			result.elements[5] = 1;
			result.elements[10] = 1;
			result.elements[15] = 1;
			result.elements[12] = translation.x;
			result.elements[13] = translation.y;
			result.elements[14] = translation.z;

			return result;
		}
		
		mat4 mat4::scale(const float3& scale)
		{
			mat4 result(0.0);

			result.elements[0] = scale.x;
			result.elements[5] = scale.y;
			result.elements[10] = scale.z;

			result.elements[15] = 1;

			return result;
		}
		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		float4 operator*(mat4 mat, float4 v)
		{
			
			float4 temp;
			temp.x = mat.GetRow(0).Dot(v);
			temp.y = mat.GetRow(1).Dot(v);
			temp.z = mat.GetRow(2).Dot(v);
			temp.w = mat.GetRow(3).Dot(v);
			return temp;
		}
	}
}