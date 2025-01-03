/* Include files */

#include "Scheme2_mod_cgxe.h"
#include "m_F6Yw7f4GZAlqQDbENKozUG.h"

unsigned int cgxe_Scheme2_mod_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 3866234637 &&
      ssGetChecksum1(S) == 1254314798 &&
      ssGetChecksum2(S) == 3745554390 &&
      ssGetChecksum3(S) == 556292422) {
    method_dispatcher_F6Yw7f4GZAlqQDbENKozUG(S, method, data);
    return 1;
  }

  return 0;
}
