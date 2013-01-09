#include "lib.h"
#include <time.h>
#define CZAS(co) clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&co)
int main(void){
	//tests();
	POLYGON temp;
	assert(get_size(&temp.size_points)==TRUE);
	alloc_points(&temp.max_of_x,&temp.points,temp.size_points);
	temp.segments=create_segments(temp.size_points);
	add_segments(temp.points,temp.segments,temp.size_points);
	draw_polygon(temp);
	triangulal_polygol(temp); 
	printf("Potrzeba %d straznikow\n",coloring_sl(temp.points,temp.segments,temp.size_points));
	print_colors(temp.points,temp.size_points);
	draw_polygon(temp);
	free_segments(temp.segments,temp.size_points);
	free_points(temp.points);
	return EXIT_SUCCESS;
}
