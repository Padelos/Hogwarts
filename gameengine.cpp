#include "gameengine.h"


GameEngine::GameEngine()
{
    this->p = Player(P);
    this->ai = PlayerAI();
    this->gem = Gem();
}

void GameEngine::initScreen()
{
    initscr();

    noecho(); 
    keypad(stdscr, TRUE);
    curs_set(0);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    this->displayScreen();
}

void GameEngine::displayScreen(){

    int i;
    int rows = map.getRows();

    attron(COLOR_PAIR(4));
    for(i = 0; i < rows; i++){
        mvprintw(i,0,"%s",map.getMap()[i]);
    }
    attroff(COLOR_PAIR(4));

    list<GameObject *> objs = map.getLocations();

    char **tmpNames;

    for(GameObject *tmp : objs){
        int i = tmp->getID();
        
        attron(COLOR_PAIR(i+1));
        mvaddch(tmp->getX(),tmp->getY(),objNames[i]);
        attroff(COLOR_PAIR(i+1));
        
    }
    
    refresh();
}

void GameEngine::run(char* file)
{
    map.setPath(std::string(file));
    if(!map.loadMap()){
        throw("The given file to read the map does not exists");
    }

    map+= this->p;
    map+= this->ai;
    map+= this->gem;
    
    ai.setMap(&map);
    

    this->initPositions();

    this->initScreen();

    // get input
    int ch;
    Cords newCord;
    bool running = true; // if hit ESC
    bool validPos;
    GameObject *foundBy = nullptr;
    
    do{
        do{
            ch = getch();
            
            string tmp = "DEFAULT";
            validPos = false;
            
            switch (ch) {
                case KEY_UP:
                    newCord = {p.getX() - 1,p.getY() + 0};
                    tmp = "UP";
                    break;
                case KEY_DOWN:
                    newCord = {p.getX() + 1,p.getY() + 0};
                    tmp = "DOWN";
                    break;
                case KEY_LEFT:
                    newCord = {p.getX() + 0,p.getY() - 1};
                    tmp = "LEFT";
                    break;
                case KEY_RIGHT:
                    newCord = {p.getX() + 0,p.getY() + 1};
                    tmp = "RIGHT";
                    break;
                case KEY_SPACE:
                    newCord = {p.getX(),p.getY()};
                    tmp = "SPACE";
                    break;
                case KEY_ESC:
                    tmp = "ESC";
                    running = false;
                    break;
                default:
                    break;
            }

            
            const char *ptr = tmp.c_str();
            
            

            move(map.getRows()+2,0);
            clrtoeol();
            printw("%s",ptr);
            
            if(!running)
                break;


            validPos = map.setCordsOf(&p,newCord);

            // if not valid get again
            // make player move
        }while(running && !validPos);

        
        if(!running){
            this->displayScreen();
            break;
        }
        

        // make ai move
        ai.findClosestCell();
        Cords aiMove = ai.returnMove();
        newCord = {ai.getX()+aiMove.getX(), ai.getY()+aiMove.getY()};

        validPos = map.setCordsOf(&ai,newCord);

        // check if someone find the GEM

        foundBy = gemFound();

        if(foundBy == nullptr){


            int rounds = gem.getRounds();

            if( rounds == 0){
                setGemRounds();
                randomPosition(&gem);
                
            }
            else{
                gem -= 1;
            }
            // if not check gem rounds
            // if 0 make new random place and set new rounds
            // else if just -1 round
        }


        this->displayScreen();

    }while(foundBy==nullptr);


    if(foundBy==nullptr)
        mvprintw(map.getRows()+3,0,"TIE!");
    else{
        if(foundBy->getID() == P)
            mvprintw(map.getRows()+3,0,"YOU WON!!!");
        else
            mvprintw(map.getRows()+3,0,"YOU LOST...");
    }
    

    refresh();
    halfdelay(20);
    getch();

    endwin();

    // map.display();
}

GameObject *GameEngine::gemFound(){

    for(GameObject *tmp : map.getLocations()){
        if ( (tmp->getID() != G) && (*tmp == gem) )
            return tmp;
    }

    return nullptr;
}

void GameEngine::setGemRounds(){
    srand((unsigned) time(NULL));
    gem.setRounds( (1 + (rand() % 10)) ); // 1 - 10 rounds
}

void GameEngine::initPositions()
{

    int mapCols = map.getCols();
    int mapRows = map.getRows();

    GameObject *arr[] = {&p, &ai, &gem};

    
    srand((unsigned) time(NULL));

    int tmpR = 1;
    int tmpC = 1;
    Cords cord;

    bool flag = false;


    for(GameObject *tmp : arr){
        
        randomPosition(tmp);
    }

    this->setGemRounds();
}


void GameEngine::randomPosition(GameObject *obj){

    int mapCols = map.getCols();
    int mapRows = map.getRows();

    srand((unsigned) time(NULL));

    int tmpR = 1;
    int tmpC = 1;
    Cords cord;

    bool flag = false;

        
    do{
        flag = false;
        tmpR = 1 + (rand() % (mapRows-2) ); // begins from 1 and ends before the wall
        tmpC = 1 + ( (rand() + 50) % (mapCols-2) ); // + 50 cause we could get the same value as the above if they have same size

        cord = {tmpR,tmpC};

        flag = map.setCordsOf(obj,cord);
    }while(!flag);

}