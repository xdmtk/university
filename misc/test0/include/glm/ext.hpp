///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2012 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @file glm/glm.hpp
/// @date 2009-05-01 / 2011-05-16
/// @author Christophe Riccio
///
/// @ref core (Dependence)
/// 
/// @defgroup gtc GTC Extensions (Stable)
///
/// @brief Functions and types that the GLSL specification doesn't define, but useful to have for a C++ program.
/// 
/// GTC extensions aim to be stable. 
/// 
/// Even if it's highly unrecommended, it's possible to include all the extensions at once by
/// including <glm/ext.hpp>. Otherwise, each extension needs to be included  a specific file.
/// 
/// @defgroup gtx GTX Extensions (Experimental)
/// 
/// @brief Functions and types that the GLSL specification doesn't define, but 
/// useful to have for a C++ program.
/// 
/// Experimental extensions are useful functions and types, but the development of
/// their API and functionality is not necessarily stable. They can change 
/// substantially between versions. Backwards compatibility is not much of an issue
/// for them.
/// 
/// Even if it's highly unrecommended, it's possible to include all the extensions 
/// at once by including <glm/ext.hpp>. Otherwise, each extension needs to be 
/// included  a specific file.
/// 
/// @defgroup virtrev VIRTREV Extensions
/// 
/// @brief Extensions develop and maintain by Mathieu [matrem] Roumillac
/// (http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showprofile&User=22660).
///////////////////////////////////////////////////////////////////////////////////

#ifndef glm_ext
#define glm_ext

#if(defined(GLM_MESSAGES) && !defined(GLM_MESSAGE_EXT_INCLUDED_DISPLAYED))
#	define GLM_MESSAGE_EXT_INCLUDED_DISPLAYED
#	pragma message("GLM: All extensions included (not recommanded)")
#endif//GLM_MESSAGES

#include "glm/gtc/half_float.hpp"
#include "glm/gtc/matrix_access.hpp"
#include "glm/gtc/matrix_integer.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/swizzle.hpp"
#include "glm/gtc/type_precision.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "glm/gtx/associated_min_max.hpp"
#include "glm/gtx/bit.hpp"
#include "glm/gtx/closest_point.hpp"
#include "glm/gtx/color_cast.hpp"
#include "glm/gtx/color_space.hpp"
#include "glm/gtx/color_space_YCoCg.hpp"
#include "glm/gtx/compatibility.hpp"
#include "glm/gtx/component_wise.hpp"
#include "glm/gtx/epsilon.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/extend.hpp"
#include "glm/gtx/extented_min_max.hpp"
#include "glm/gtx/fast_exponential.hpp"
#include "glm/gtx/fast_square_root.hpp"
#include "glm/gtx/fast_trigonometry.hpp"
#include "glm/gtx/gradient_paint.hpp"
#include "glm/gtx/handed_coordinate_space.hpp"
#include "glm/gtx/inertia.hpp"
#include "glm/gtx/int_10_10_10_2.hpp"
#include "glm/gtx/integer.hpp"
#include "glm/gtx/intersect.hpp"
#include "glm/gtx/log_base.hpp"
#include "glm/gtx/matrix_cross_product.hpp"
#include "glm/gtx/matrix_interpolation.hpp"
#include "glm/gtx/matrix_major_storage.hpp"
#include "glm/gtx/matrix_operation.hpp"
#include "glm/gtx/matrix_query.hpp"
#include "glm/gtx/mixed_product.hpp"
#include "glm/gtx/multiple.hpp"
#include "glm/gtx/noise.hpp"
#include "glm/gtx/norm.hpp"
#include "glm/gtx/normal.hpp"
#include "glm/gtx/normalize_dot.hpp"
#include "glm/gtx/number_precision.hpp"
#include "glm/gtx/ocl_type.hpp"
#include "glm/gtx/optimum_pow.hpp"
#include "glm/gtx/orthonormalize.hpp"
#include "glm/gtx/perpendicular.hpp"
#include "glm/gtx/polar_coordinates.hpp"
#include "glm/gtx/projection.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/random.hpp"
#include "glm/gtx/raw_data.hpp"
#include "glm/gtx/reciprocal.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/spline.hpp"
#include "glm/gtx/std_based_type.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/transform2.hpp"
#include "glm/gtx/ulp.hpp"
#include "glm/gtx/vec1.hpp"
#include "glm/gtx/vector_access.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "glm/gtx/vector_query.hpp"
#include "glm/gtx/verbose_operator.hpp"
#include "glm/gtx/wrap.hpp"

#if(GLM_ARCH & GLM_ARCH_SSE2)
#	include "./gtx/simd_vec4.hpp"
#	include "./gtx/simd_mat4.hpp"
#endif

#include "glm/virtrev/xstream.hpp"

//const float goldenRatio = 1.618033988749894848f;
//const float pi = 3.141592653589793238f;

#endif //glm_ext
