#include <types.h>

void print(const char *string,Color forecolor,Color backcolor){
	/*
				Text Mode 16 bit
					Layout
					
		[15     12  11      8   7       0 ]
    	[Backcolor  Forecolor   Character ]
    */

    u16 * video_addr = (u16 *)0xB8000;
    while( *string != '\0' )
    {
        *video_addr++ = backcolor << 12 | forecolor << 8 | *string++;
    }
}
void clear(){

	const size_t screen_size = 80*25;
	
	const Color backcolor = BLACK;
	const Color forecolor = BLACK;
	
	const char blank = ' ';
	
	u16 * video_addr = (u16 *)0xB8000;
	for(int i = 0;i< screen_size;++i)
    {
        *video_addr++ = backcolor << 12 | forecolor << 8 | blank;
    }
}
void _kernel(struct multiboot *mboot_ptr)
{
	clear();
    print("Hello World",WHITE,BLACK);
}

