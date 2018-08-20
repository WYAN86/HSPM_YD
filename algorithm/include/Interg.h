
/* File name:        INTERG.h     */              
#pragma CODE_SECTION(fnInterg_Calc, "ramfuncs")                    

typedef struct {  
                 /*�������*/
				  float32  fIn;
				 /*���ò���*/
				  float32  fKp;				// 
				  float32  fTs;				//  
				  float32  fUpLmt;	    	// ����ֵ
				  float32  fLwLmt;   		// ����ֵ
				  float32  fFlag;
				  float32  fKs;  

				  /*�м����*/
				  float32  fOutformer;		     	// 
				  float32  fInformer;

				  /*�������*/
				  float32  fOut;			    // 


		 	 	  void  (*pfnCalc)();	  	// Pointer to calculation function
				 } INTERG;	           


/*-----------------------------------------------------------------------------
Default initalizer for the VIMC_pid object.
-----------------------------------------------------------------------------*/                     
#define INTERG_DEFAULTS {  0, \
                           0,0,30000.0,-30000.0,0,1, \
						   0,0,\
						   0,\
              			  (void (*)(Uint32))fnInterg_Calc }

void fnInterg_Calc(INTERG *p);

