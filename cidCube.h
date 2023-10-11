#ifndef __CIDCUBE__
#define __CIDCUBE__

#include <memory>
#include <utility>
#include <tuple>

namespace cid 
{

    #define IDX static_cast<unsigned int>

	namespace gfx
	{
		


	

		struct vert
		{
			enum class type : unsigned int
			{
				_2D = 4, _3D = 8
			};

			private:
				type m_t;

				float m_x;  // 8 vertices in a cube, 4 on a square
				float m_y;
				float m_z;

			public:
				explicit vert(float l_xpos = 0, float l_ypos = 0, float l_zpos = 0, type l_type = type::_3D)
					: m_x(l_xpos)
					, m_y(l_ypos)
					, m_z(l_zpos)
					, m_t(l_type)
				{
					if (l_type == type::_2D)
						m_z = -1;
				}

				vert& operator=(vert&& l_o)
				{
					*this = std::move(l_o);
					return *this;
				}
				
				vert(std::tuple<float, float, float>&& l_tpl)
				{
					this->m_x = std::get<0>(l_tpl);
					this->m_y = std::get<0>(l_tpl);
					this->m_z = std::get<0>(l_tpl);
					m_t = type::_3D;
				}
		};


		struct Cube
		{
			private:

				vert ices[IDX(vert::type::_3D)]{ 
					std::make_tuple<float,float,float>(1.f,1.f,1.f),std::make_tuple<float,float,float>(1.f,2.f,1.f),
					std::make_tuple<float,float,float>(2.f,2.f,1.f),std::make_tuple<float,float,float>(2.f,1.f,1.f),
					std::make_tuple<float,float,float>(2.f,2.f,2.f),std::make_tuple<float,float,float>(1.f,2.f,2.f),
					std::make_tuple<float,float,float>(1.f,1.f,2.f),std::make_tuple<float,float,float>(2.f,1.f,2.f)
				};
				
				float m_x;
				float m_y;
				float m_z;

				float m_l;
				float m_w;
				float m_h;

				

			public:
				explicit Cube(int l_w = 64, int l_h = 64, int l_d = 64, int l_xpos = 0, int l_ypos = 0, int l_zpos = 0)
					: m_x(l_xpos), m_y(l_ypos), m_z(l_zpos)
					, m_l(l_d), m_w(l_w), m_h(l_h)
				{

				}

		};
	}

}



#endif
