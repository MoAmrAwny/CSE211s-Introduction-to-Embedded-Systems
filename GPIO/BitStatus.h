#ifndef BitStatus_H
#define BitStatus_H
#endif

#define SET(REG,VALUE)  REG |= VALUE                    
#define CLR(REG,VALUE)  REG &=~ VALUE										

#define SET_BIT(REG,BIT)  REG |= (1<<BIT)

#define GET_BIT(REG,BIT)  ((REG>>BIT)&1)
#define CLR_BIT(REG,BIT)  REG &=~ (1<<BIT)


