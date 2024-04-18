#include "pch.h"
#include "Game.h"
#include "character.h"
#include <random>

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();


	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  enemies(5, 30);

	std::uniform_int_distribution<int>  wH(0, window.height);
	std::uniform_int_distribution<int>  wW(0, window.width);
	for (size_t i = 0; i < enemies(generator); ++i)
	{
		Enemies.push_back(new character());
	}
	for (size_t i = 0; i < Enemies.size(); ++i)
	{
		Enemies.at(i)->XLoc = wH(generator);
		Enemies.at(i)->YLoc = wW(generator);
		Enemies.at(i)->Speed = 1;
	}
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	Player = new character();
}

void Game::Cleanup( )
{
	delete Player;
	for (size_t i = 0; i < Enemies.size(); i++)
	{
		delete Enemies.at(i);
	}
}

void Game::Update( float elapsedSec )
{
	Player->Update(elapsedSec);
	// Check keyboard state
	const uint8_t *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
	Player->Move(pStates);
	for (size_t i = 0; i < Enemies.size(); i++)
	{
		Enemies.at(i)->MoveToPlayer(Point2f(Player->XLoc, Player->YLoc));
	}
}

void Game::Draw( ) const
{
	ClearBackground( );
	Player->Draw();
	for (size_t i = 0; i < Enemies.size(); i++)
	{
		Enemies.at(i)->Draw();
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
	Player->MousePos = Point2f(e.x,e.y);
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	Player->Attack();
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	Player->bIsShoots = false;
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
