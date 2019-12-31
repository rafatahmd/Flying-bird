#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include<fstream>

using namespace sf;
using namespace std;
const int SCREEN_WIDTH=1000;
const int SCREEN_HEIGH=600;
int highscore=0;
int score=0;
RenderWindow window(VideoMode(1000, 600), "Flying Bird");
// rect rect collision detection helper function
bool collides(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2)
    {
        return true;
    }
    return false;
}
int startGame();
int startGame()
{
start :
    cout << 1;

//menu music
    SoundBuffer menusoundbuffer;
    menusoundbuffer.loadFromFile("gamesound2.wav");
    Sound MenuSound;
    MenuSound.setBuffer(menusoundbuffer);

//Loading Background Image
    float yposition = SCREEN_HEIGH/6*2;
    Texture Background;
    if ( !Background.loadFromFile("down.jpg") )
        return EXIT_FAILURE;
    Sprite background(Background);

//Font for menu
    Font myfont;
    myfont.loadFromFile("rafat.ttf");

//Text for Menu
    string menu[6], Game;
    Game = "Flying Bird";
    menu[0] = "Play";
    menu[1] = "High Score";
    menu[2] = "Credits";
    menu[3] = " Exit";
    menu[4]= "Developed by";
    menu[5]= "Arif & Rafat";
    Text name ( Game, myfont, 60 ), game ( menu[0], myfont, 35 ), high ( menu[1], myfont, 35 ), cre ( menu[2], myfont, 35 ), exit ( menu[3], myfont, 35 ), dev1 (menu[4],myfont,30), dev2(menu[5],myfont,30);

//Text Design
    name.setOutlineThickness(2.5);
    game.setOutlineThickness(5);
    high.setOutlineThickness(5);
    cre.setOutlineThickness(5);
    exit.setOutlineThickness(5);
    dev1.setOutlineThickness(5);
    dev2.setOutlineThickness(5);
    name.setFillColor(sf::Color::Blue);
    game.setFillColor(sf::Color::Green);
    high.setFillColor(sf::Color::Red);
    cre.setFillColor(sf::Color::Red);
    exit.setFillColor(sf::Color::Red);
    dev1.setFillColor(sf::Color::Cyan);
    dev2.setFillColor(sf::Color::Green);


//positions for options
    background.setPosition(0,0);
    name.setPosition(SCREEN_WIDTH/2-160, SCREEN_HEIGH/6*1);
    game.setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGH/6*2);
    high.setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGH/6*3);
    cre.setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGH/6*4);
    exit.setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGH/6*5);
    dev1.setPosition(SCREEN_WIDTH/2-40, SCREEN_HEIGH/6*5);
    dev1.setPosition(SCREEN_WIDTH/2-40, SCREEN_HEIGH/6*6);

    MenuSound.play();
    MenuSound.setLoop(true);


    while ( window.isOpen())
    {
        int highvisit = 0;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if ( yposition == SCREEN_HEIGH/6*2 )
            {
                game.setStyle(Text::Italic);
                high.setStyle(Text::Regular);
                cre.setStyle(Text::Regular);
                exit.setStyle(Text::Regular);

                game.setFillColor(sf::Color::Green);
                high.setFillColor(sf::Color::Red);
                cre.setFillColor(sf::Color::Red);
                exit.setFillColor(sf::Color::Red);
            }
            else if ( yposition == SCREEN_HEIGH/6*3 )
            {
                game.setStyle(Text::Regular);
                high.setStyle(Text::Italic);
                cre.setStyle(Text::Regular);
                exit.setStyle(Text::Regular);

                game.setFillColor(sf::Color::Red);
                high.setFillColor(sf::Color::Green);
                cre.setFillColor(sf::Color::Red);
                exit.setFillColor(sf::Color::Red);
            }
            else if ( yposition == SCREEN_HEIGH/6*4 )
            {
                game.setStyle(Text::Regular);
                high.setStyle(Text::Regular);
                cre.setStyle(Text::Italic);
                exit.setStyle(Text::Regular);

                game.setFillColor(sf::Color::Red);
                high.setFillColor(sf::Color::Red);
                cre.setFillColor(sf::Color::Green);
                exit.setFillColor(sf::Color::Red);
            }
            else if ( yposition == SCREEN_HEIGH/6*5 )
            {
                game.setStyle(Text::Regular);
                high.setStyle(Text::Regular);
                cre.setStyle(Text::Regular);
                exit.setStyle(Text::Italic);


                game.setFillColor(sf::Color::Red);
                high.setFillColor(sf::Color::Red);
                cre.setFillColor(sf::Color::Red);
                exit.setFillColor(sf::Color::Green);
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if ( event.key.code == sf::Keyboard::Enter )
                {
                    if ( yposition == SCREEN_HEIGH/6*2 )
                        return 0;
                    if ( yposition == SCREEN_HEIGH/6*3 )
                    {
                        string note = "High Score : " + to_string(highscore);
                        Text highscore(note, myfont, 30), goback("Press Esc to go back to main menu", myfont, 30);
                        highscore.setPosition(SCREEN_WIDTH/2-160,SCREEN_HEIGH/2-160);
                        goback.setPosition(SCREEN_WIDTH/2-160,SCREEN_HEIGH/2);

//Text Style
                        highscore.setFillColor(Color::Magenta);
                        goback.setFillColor(Color::Blue);
                        highscore.setOutlineThickness(5);
                        goback.setOutlineThickness(5);

                        while (window.isOpen())
                        {
                            Event high_event;
                            while ( window.pollEvent(high_event) )
                            {
                                if ( high_event.type == high_event.Closed )
                                    window.close();
                                if ( high_event.type == high_event.KeyPressed)
                                {
                                    if ( high_event.key.code == sf::Keyboard::Escape )
                                        goto start;
                                }
                            }
                            window.clear();
                            window.draw(background);
                            window.draw(highscore);
                            window.draw(goback);
                            window.display();
                        }
                    }
                    if ( yposition == SCREEN_HEIGH/6*4 )
                    {
                        string Role1, Role2, Role3, Sir, Us[4], Internet;
                        Role1 = "Created under the observation of";
                        Sir = "Quazi Ishtiaque Mahmud";
                        Role2 = "Developed By";
                        Us[0] = "Rafat Khan";
                        Us[1] = "Md Ariful Islam";

                        Us[3] = "TEAM LOPPER";

                        Text role1(Role1, myfont, 30), role2(Role2, myfont, 30), role3(Role3, myfont, 30), sir(Sir, myfont, 50), arif(Us[1], myfont, 30), rafat(Us[0], myfont, 30), faltu(Us[2], myfont, 30), Team(Us[3], myfont, 60), internet(Internet, myfont, 30);

                        role1.setFillColor(Color::Red);
                        role2.setFillColor(Color::Red);
                        role3.setFillColor(Color::Red);
                        sir.setFillColor(Color::Cyan);
                        arif.setFillColor(Color::Cyan);
                        rafat.setFillColor(Color::Cyan);
                        faltu.setFillColor(Color::Cyan);
                        Team.setFillColor(Color::Cyan);
                        internet.setFillColor(Color::Cyan);


                        role1.setPosition(SCREEN_WIDTH/2-200,SCREEN_HEIGH+30);
                        sir.setPosition(SCREEN_WIDTH/2-270,SCREEN_HEIGH+70);
                        role2.setPosition(SCREEN_WIDTH/2-100,SCREEN_HEIGH+170);
                        arif.setPosition(SCREEN_WIDTH/2-100,SCREEN_HEIGH+210);
                        rafat.setPosition(SCREEN_WIDTH/2-100,SCREEN_HEIGH+250);
                        faltu.setPosition(SCREEN_WIDTH/2-30,SCREEN_HEIGH+290);
                        Team.setPosition(SCREEN_WIDTH/2-190,SCREEN_HEIGH+530);
                        role3.setPosition(SCREEN_WIDTH/2-220,SCREEN_HEIGH+430);
                        internet.setPosition(SCREEN_WIDTH/2-40,SCREEN_HEIGH+470);

                        role1.setOutlineThickness(5);
                        sir.setOutlineThickness(5);
                        role2.setOutlineThickness(5);
                        arif.setOutlineThickness(5);
                        rafat.setOutlineThickness(5);
                        faltu.setOutlineThickness(5);
                        Team.setOutlineThickness(5);
                        role3.setOutlineThickness(5);
                        internet.setOutlineThickness(5);

                        while(window.isOpen())
                        {
                            window.setFramerateLimit(100);
                            Event Creditevent;
                            while( window.pollEvent(Creditevent) )
                            {
                                if ( Creditevent.type == Creditevent.Closed )
                                    window.close();
                                if ( Creditevent.type == Creditevent.KeyPressed && Creditevent.key.code == Keyboard::Escape )
                                    goto start;
                            }
                            role1.move(0, -1);
                            sir.move(0,-1);
                            role2.move(0, -1);
                            arif.move(0, -1);
                            rafat.move(0, -1);
                            faltu.move(0, -1);
                            Team.move(0, -1);
                            role3.move(0, -1);
                            internet.move(0, -1);

                            window.clear();
                            window.draw(background);
                            window.draw(role1);
                            window.draw(role2);
                            window.draw(role3);
                            window.draw(sir);
                            window.draw(rafat);
                            window.draw(arif);

                            window.draw(faltu);
                            window.draw(Team);
                            window.draw(internet);
                            window.display();
                        }


                    }
                    if ( yposition == SCREEN_HEIGH/6*5 )
                    {
                        window.close();
                    }
                }
                if ( event.key.code == sf::Keyboard::Up )
                {
                    yposition -= SCREEN_HEIGH/6;
                    if ( yposition < SCREEN_HEIGH / 6*2 )
                    {
                        yposition = SCREEN_HEIGH/6*5;
                    }
                }
                if ( event.key.code == sf::Keyboard::Down )
                {
                    yposition += SCREEN_HEIGH/6;
                    if ( yposition > SCREEN_HEIGH / 6*5 )
                    {
                        yposition = SCREEN_HEIGH/6*2;
                    }
                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(name);
        window.draw(game);
        window.draw(high);
        window.draw(cre);
        window.draw(exit);
        window.draw(dev1);
        window.draw(dev2);
        window.display();
    }
}

int main()
{
  std::ifstream readFile;
readFile.open("highscore.txt");
if ( readFile.is_open() )
{
while( !readFile.eof() )
{
readFile >> highscore;
}
}
readFile.close();



    startGame();
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    srand(time(0));


    struct Sounds
    {
        SoundBuffer chingBuffer;
        SoundBuffer hopBuffer;
        SoundBuffer dishkBuffer;
        Sound ching;
        Sound hop;
        Sound dishk;
        SoundBuffer menusoundbuffer;
        Sound MenuSound;


    } sounds;

    // load sounds
    sounds.chingBuffer.loadFromFile("score.wav");
    sounds.hopBuffer.loadFromFile("flap.wav");
    sounds.dishkBuffer.loadFromFile("crash.wav");
    sounds.ching.setBuffer(sounds.chingBuffer);
    sounds.hop.setBuffer(sounds.hopBuffer);
    sounds.dishk.setBuffer(sounds.dishkBuffer);
    SoundBuffer menusoundbuffer;
    menusoundbuffer.loadFromFile("gamesound.wav");
    Sound MenuSound;
    MenuSound.setBuffer(menusoundbuffer);
    MenuSound.play();
    MenuSound.setLoop(true);

    struct Textures
    {
        Texture flappy[3];
        Texture pipe;
        Texture background;
        Texture gameover;
    } textures;

    // load textures
    textures.background.loadFromFile("background.png");
    textures.pipe.loadFromFile("pipe.png");
    textures.gameover.loadFromFile("gameover.png");
    textures.flappy[0].loadFromFile("flappy1.png");
    textures.flappy[1].loadFromFile("flappy2.png");
    textures.flappy[2].loadFromFile("flappy3.png");


    struct Flappy
    {
        double v = 0;
        int frame = 0;
        Sprite sprite;
    } flappy;

    // initial position, scale
    flappy.sprite.setPosition(250, 300);
    flappy.sprite.setScale(2, 2);

    // resizable array of sprites representing pipes
    vector<Sprite> pipes;


    enum GameState { waiting,
                     started,
                     gameover
                   };





    struct Game
    {
        int score = 0;
        int highscore = 0;
        int frames = 0;
        GameState gameState = waiting;
        Sprite background[3];
        Sprite gameover;
        Text pressC;
        Text pressB;
        Text scoreText;
        Text pressP;
        Text pressL;
        Text pressG;
        Text pressD;
        Text highscoreText;
        Font font;
    } game;


    // load font, set positions, scales etc
    game.font.loadFromFile("font2.ttf");
    game.background[0].setTexture(textures.background);
    game.background[1].setTexture(textures.background);
    game.background[2].setTexture(textures.background);
    game.background[0].setScale(1.15625, 1.171875);
    game.background[1].setScale(1.15625, 1.171875);
    game.background[2].setScale(1.15625, 1.171875);
    game.background[1].setPosition(333, 0);
    game.background[2].setPosition(666, 0);
    game.gameover.setTexture(textures.gameover);
    game.gameover.setOrigin(96, 20);
    game.gameover.setPosition(500, 125);
    game.gameover.setScale(2, 2);
    game.pressB.setString("Press c to continue");
    game.pressC.setString("Press Esc to go");
    game.pressD.setString(" back main menu");
    game.pressP.setString("Paused");
    game.pressL.setString("Level 2");
    game.pressG.setString("Level 3");
    game.pressC.setFont(game.font);
    game.pressB.setFont(game.font);
    game.pressP.setFont(game.font);
    game.pressL.setFont(game.font);
    game.pressG.setFont(game.font);
    game.pressD.setFont(game.font);
    game.pressB.setFillColor(Color::Blue);
    game.pressC.setFillColor(Color::Red);
    game.pressP.setFillColor(Color::Black);
    game.pressL.setFillColor(Color::Cyan);
    game.pressD.setFillColor(Color::Red);
    game.pressC.setCharacterSize(60);
    game.pressB.setCharacterSize(60);
    game.pressD.setCharacterSize(60);
    game.pressP.setCharacterSize(80);
    game.pressL.setCharacterSize(80);
    game.pressG.setCharacterSize(80);
    game.pressC.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressB.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressP.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressL.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressG.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressD.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressC.setPosition(500, 300);
    game.pressP.setPosition(500, 300);
    game.pressB.setPosition(500, 200);
    game.pressD.setPosition(500, 350);
    game.pressL.setPosition(600, 200);
    game.pressG.setPosition(600, 200);
    game.scoreText.setFont(game.font);
    game.scoreText.setFillColor(Color::Black);
    game.scoreText.setCharacterSize(75);
    game.scoreText.move(30, 0);
    game.highscoreText.setFont(game.font);
    game.highscoreText.setFillColor(Color::Black);
    game.highscoreText.move(30, 80);

    // main loop
    while (window.isOpen())
    {


        // update score
        flappy.sprite.setTexture(textures.flappy[1]);
        game.scoreText.setString("current score: " + to_string(game.score));
        game.highscoreText.setString("HIGH SCORE: " + to_string(game.highscore));

        // update flappy
        float fx = flappy.sprite.getPosition().x;
        float fy = flappy.sprite.getPosition().y;
        float fw = 34 * flappy.sprite.getScale().x;
        float fh = 24 * flappy.sprite.getScale().y;

        // flap the wings if playing
        if (game.gameState == waiting || game.gameState == started)
        {

            // change the texture once in 6 frames
            if (game.frames % 6 == 0)
            {
                flappy.frame += 1;
            }
            if (flappy.frame == 3)
            {
                flappy.frame = 0;
            }
        }

        flappy.sprite.setTexture(textures.flappy[flappy.frame]);

        // move flappy
        if (game.gameState == started)
        {
            flappy.sprite.move(0, flappy.v);
            flappy.v += 0.6;
        }

        // if out of screen, game over
        if (game.gameState == started)
        {
            if (fy < 0)
            {
                flappy.sprite.setPosition(250, 0);
                flappy.v = 0;
            }
            else if (fy > 600)
            {
                flappy.v = 0;
                game.gameState = gameover;
                sounds.dishk.play();

            }
        }
               std::ofstream writefile ("highscore.txt");
if ( writefile.is_open() )
{
if ( score > highscore )
highscore = score;
writefile << highscore;
}
writefile.close();

        // count the score
        for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++)
        {
            if (game.gameState == started && (*itr).getPosition().x == 250)
            {
                game.score++;
                sounds.ching.play();


                if (game.score > game.highscore)
                {
                    game.highscore = game.score;
                }

                break;
            }
        }

        // generate pipes
        if (game.gameState == started && game.frames % 100 == 0 && game.score<3 )
        {
            int r = rand() % 170 + 75;
            int gap = 160;

            // lower pipe
            Sprite pipeL;
            pipeL.setTexture(textures.pipe);
            pipeL.setPosition(1000, r + gap);
            pipeL.setScale(1, 1);

            // upper pipe
            Sprite pipeU;
            pipeU.setTexture(textures.pipe);
            pipeU.setPosition(1000, r);
            pipeU.setScale(1, -1);

            // push to the array
            pipes.push_back(pipeL);
            pipes.push_back(pipeU);
        }
        else if(game.gameState == started && game.frames % 100 == 0 && game.score>3)
        {
            int r = rand() % 190 + 70;
            int gap = 145;

            // lower pipe
            Sprite pipeL;
            pipeL.setTexture(textures.pipe);

            pipeL.setPosition(1000, r + gap);
            pipeL.setScale(1.5, 1.5);

            // upper pipe
            Sprite pipeU;
            pipeU.setTexture(textures.pipe);
            pipeU.setPosition(1000, r);
            pipeU.setScale(1.5, -1.5);

            // push to the array
            pipes.push_back(pipeL);
            pipes.push_back(pipeU);
        }
        else if	(game.gameState == started && game.frames % 100 == 0 && game.score>8)
        {
            int r = rand() % 180 + 65;
            int gap = 140;

            // lower pipe
            Sprite pipeL;
            pipeL.setTexture(textures.pipe);
            pipeL.setPosition(1000, r + gap);
            pipeL.setScale(2, 2);

            // upper pipe
            Sprite pipeU;
            pipeU.setTexture(textures.pipe);
            pipeU.setPosition(1000, r);
            pipeU.setScale(2, -2);

            // push to the array
            pipes.push_back(pipeL);
            pipes.push_back(pipeU);
        }

        // move pipes
        if (game.gameState == started)
        {
            for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++)
            {
                (*itr).move(-3, 0);
            }
        }

        // remove pipes if offscreen
        if (game.frames % 100 == 0)
        {
            vector<Sprite>::iterator startitr = pipes.begin();
            vector<Sprite>::iterator enditr = pipes.begin();

            for (; enditr != pipes.end(); enditr++)
            {
                if ((*enditr).getPosition().x > -104)
                {
                    break;
                }
            }

            pipes.erase(startitr, enditr);
        }

        // collision detection
        if (game.gameState == started)
        {
            for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++)
            {

                float px, py, pw, ph;

                if ((*itr).getScale().y > 0)
                {
                    px = (*itr).getPosition().x;
                    py = (*itr).getPosition().y;
                    pw = 52 * (*itr).getScale().x;
                    ph = 320 * (*itr).getScale().y;
                }
                else
                {
                    pw = 52 * (*itr).getScale().x;
                    ph = -320 * (*itr).getScale().y;
                    px = (*itr).getPosition().x;
                    py = (*itr).getPosition().y - ph;
                }

                if (collides(fx, fy, fw, fh, px, py, pw, ph))
                {
                    game.gameState = gameover;
                    sounds.dishk.play();
                }
            }

        }


        // events
        Event event;
        while (window.pollEvent(event))
        {

            // bye bye
            if (event.type == Event::Closed)
            {
                window.close();
            }

            // flap
            else if (event.type == Event::KeyPressed &&
                     event.key.code == Keyboard::P)
            {
                if (game.gameState == started)
                {
                    game.gameState = waiting;
                    window.draw(game.pressP);
                    //window.draw(game.pressC);


                }
            }

            else if (event.type == Event::KeyPressed &&
                     event.key.code == Keyboard::Space)
            {
                if (game.gameState == waiting)
                {
                    game.gameState = started;
                }

                if (game.gameState == started)
                {
                    flappy.v = -8;
                    sounds.hop.play();
                }


                // restart
            }
            else if(event.type == Event::KeyPressed &&
                    event.key.code == Keyboard::C &&
                    game.gameState == gameover)
            {
                game.gameState = waiting;
                flappy.sprite.setPosition(250, 300);
                game.score = 0;
                pipes.clear();
            }
            else if (event.type == Event::KeyPressed &&
                     event.key.code == Keyboard:: Escape &&
                     game.gameState == gameover)
            {
                game.gameState = waiting;
                flappy.sprite.setPosition(250, 300);
                game.score = 0;
                pipes.clear();
                startGame();
            }
        }

        // clear, draw, display
        window.clear();
        window.draw(game.background[0]);
        window.draw(game.background[1]);
        window.draw(game.background[2]);
        window.draw(flappy.sprite);


        // draw pipes
        for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++)
        {
            window.draw(*itr);
        }

        // draw scores
        window.draw(game.scoreText);
        window.draw(game.highscoreText);

        // gameover. press c to continue
        if (game.gameState == gameover)
        {
            window.draw(game.gameover);
            //window.draw(game.pressB);


            if (game.frames % 40 < 20)
            {
                window.draw(game.pressC);
                window.draw(game.pressD);
                window.draw(game.pressB);

            }
        }
        if (game.gameState == waiting &&
                event.key.code == Keyboard::P)
        {
            window.draw(game.pressP);
        }
        if(game.score >= 5 && game.score < 6 )
        {
            window.draw(game.pressL);

        }
        if(game.score >= 10 && game.score < 11 )
        {
            window.draw(game.pressG);

        }
        window.display();

        // update total frames
        game.frames++;
    }


    return 0;
}



