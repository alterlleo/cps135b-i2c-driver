/*

   ____ ____  ____  _ _________  ____  
  / ___|  _ \/ ___|/ |___ / ___|| __ ) 
 | |   | |_) \___ \| | |_ \___ \|  _ \ 
 | |___|  __/ ___) | |___) |__) | |_) |
  \____|_|   |____/|_|____/____/|____/ 
                                       

According to datasheet, CPS135B can work in 2 states: it is in SLEEP mode until a measurement request (MR) message occurs. When it comes, the sensor wakes up, measures and stores the measure value in internal registers and then it returns in sleep mode
*/

#include "cps135b.h"

