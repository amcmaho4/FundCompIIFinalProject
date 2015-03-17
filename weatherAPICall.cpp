#include <cstdio>
#include <cstdlib>

int main ()
{
	system("curl https://query.yahooapis.com/v1/public/yql \
	-d q=\"select wind from weather.forecast where woeid=2460286\" \
		   -d format=json > file");
	system("open file");
	
}