/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2011-2013 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_CORE_H
#define AVOGADRO_CORE_H

#include "avogadrocoreexport.h"
#include <cstddef>
#include <limits>

/** Prevent compiler error when using std::numeric_limits<T>::max() */
#if defined(_MSC_VER) && defined(max)
#undef max
#endif

/**
 * Define a macro for the new C++11 override and final identifiers when using
 * a compiler with C++11 support enabled.
 */
#if __cplusplus >= 201103L
# define AVO_OVERRIDE override
# define AVO_FINAL final
# define AVO_NULLPTR nullptr
#else
# define AVO_OVERRIDE
# define AVO_FINAL
# define AVO_NULLPTR NULL
#endif

/**
 * This macro marks a parameter as unused. Its purpose is to disable the
 * compiler from emitting unused parameter warnings.
 */
#define AVO_UNUSED(variable) (void) variable

/**
 * This macro marks a class as not copyable. It should be used in the private
 * section of a class's declaration.
 */
#define AVO_DISABLE_COPY(Class) \
  Class(const Class&); \
  Class& operator=(const Class&);

namespace Avogadro {

/** Typedef for a real number. */
typedef double Real;

/** Typedef for indices and sizes. */
typedef size_t Index;
const Index MaxIndex = std::numeric_limits<Index>::max();

/** Used to represent an invalid atomic number. */
const unsigned char InvalidElement = 255;

/**
 * Minimum value for atomic numbers that represent custom, non-elemental
 *  particles. */
const unsigned char CustomElementMin = 128;

/**
 * Maximum value for atomic numbers that represent custom, non-elemental
 *  particles. */
const unsigned char CustomElementMax = 254;

/**
 * Count of atomic number values that are used to represent custom,
 * non-elemental particles. */
const unsigned char CustomElementCount =
    CustomElementMax - CustomElementMin + 1;

/**
 * @return True if @a atomicNumber denotes a custom element type.
 */
namespace Core {
inline bool isCustomElement(unsigned char atomicNumber)
{
  return atomicNumber >= CustomElementMin && atomicNumber <= CustomElementMax;
}
}

/** Unit conversion factors. @{ */
const double PI_D = 3.141592653589793238462643;
const float PI_F = static_cast<float>(PI_D);
const Real PI = static_cast<Real>(PI_D);

const double DEG_TO_RAD_D = PI_D / 180.0;
const float DEG_TO_RAD_F = static_cast<float>(DEG_TO_RAD_D);
const Real DEG_TO_RAD = static_cast<Real>(DEG_TO_RAD_D);

const double RAD_TO_DEG_D = 180.0 / PI_D;
const float RAD_TO_DEG_F = static_cast<float>(RAD_TO_DEG_D);
const Real RAD_TO_DEG = static_cast<Real>(RAD_TO_DEG_D);

const double BOHR_TO_ANGSTROM_D = 0.52917721092;
const float BOHR_TO_ANGSTROM_F = static_cast<float>(BOHR_TO_ANGSTROM_D);
const Real BOHR_TO_ANGSTROM = static_cast<Real>(BOHR_TO_ANGSTROM_D);

const double ANGSTROM_TO_BOHR_D = 1.0 / BOHR_TO_ANGSTROM_D;
const float ANGSTROM_TO_BOHR_F = static_cast<float>(ANGSTROM_TO_BOHR_D);
const Real ANGSTROM_TO_BOHR = static_cast<Real>(ANGSTROM_TO_BOHR_D);
/** @} */

} // end Avogadro namespace

#endif // AVOGADRO_CORE_H
