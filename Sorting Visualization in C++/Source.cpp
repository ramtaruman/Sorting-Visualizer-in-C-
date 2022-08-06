
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>


void show_current_state(std::vector<int>& v, SDL_Renderer* renderer, long red, long blue)
{
	int current_i = 0;
	for (int i : v) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderDrawLine(renderer, current_i, 99, current_i, i); //draws line starting from left to right, line height is defined by i
		current_i++;
	}
}




int main()
{
	std::random_device rand_dev;
	std::uniform_int_distribution<> distrib(1,99 ); // generates the  random numbers for populating purposes
	
	std::vector<int> v; //Our container which will store the values

	for (int i = 0; i < 100; i++) // populate our vector v with a bunch of random numbers
	{
		v.push_back(distrib(rand_dev));
	}
	/// creating a window in the renderer /// 

	SDL_Window* window_A;
	SDL_Renderer* renderer_A;
	SDL_CreateWindowAndRenderer(100*10 , 100*10 , 0, &window_A, &renderer_A);
	SDL_RenderSetScale(renderer_A, 8, 8);

	//// end of creating window //// 






	/// sort algo ? /// // bubble 

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			if (v[j] > v[i])
			{
				std::swap(v[j], v[i]);
			}

			//clears the screen first

			SDL_SetRenderDrawColor(renderer_A, 0, 0, 0, 255);
			SDL_RenderClear(renderer_A);



			//render the current state of the sort

			show_current_state(v, renderer_A, i, j);

			//displays the current render

			SDL_RenderPresent(renderer_A);
		}
	}
	
	
}