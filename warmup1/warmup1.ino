/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!							
#								
!	Name:       Nicholas Martinez	
#	Class:		COMP 522 - Section 21648
!	Instructor:	Adam Kaplan
#	Date:		9/2/2020
!									    
#	        Warmup 1
!									     
#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!*/




/* Some macros for pins and constants */
#define ANALOG_IN A0
#define DIGITAL_OUT 6
#define MAP_SIZE 1024
#define MAP_OFFSET 4


/* Make some space to map the values from (0-1023) to (0-255) */
unsigned char a2d[MAP_SIZE];

/* Perform the mapping operation on setup */
void setup() {

    /* Since 1024/256 = 4, each set of 4 in 1024 will map to 1 number in 256 */
    for (short i=0, j=0; i < MAP_SIZE; i+= MAP_OFFSET, ++j) 

        /* Map 'j' (increments by 1) to the offset 'i' (increments by 4) of a2d[] */
        memset(a2d+i, j, MAP_OFFSET);
}


/* Write out the mapped value of what is read in */
void loop() {
    
    /* Quick access to a2d map value for writing out */
    analogWrite(DIGITAL_OUT, a2d[analogRead(ANALOG_IN)]);
}
