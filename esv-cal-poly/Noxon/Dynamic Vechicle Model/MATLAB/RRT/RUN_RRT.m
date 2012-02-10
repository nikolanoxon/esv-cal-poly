function FINAL_PATH = RUN_RRT(VEHICLE, OBSTACLE, ROAD, GOAL)

%BEGINNING OF SIMULINK BLOCK*******************************    
%LOOPAL INITIALIZATION*****************
%WHAT WILL BE IN THE SIMULINK BLOCK
TEMP_NODE= zeros(3);    %[x,y,cn]
TREE=zeros(500, 3);    %[x,y,cn]
ROUTE_TREE=zeros(400,2);%[x,y]
PATH=zeros(50,6);      %[x,y,theta,delta,t]
NODE_DIST=5;
DONE=0;
NODES=1;
RAND_GO=0;
TREE=zeros(500,3);
FINAL_TREE=zeros(20,2);
TREE(1,1:2)=VEHICLE(1:2);
TREE(1,3)=0;
FAIL=0;
ITERATIONS=0;
VEHICLE_GEO=[2,1.5];

%RANDOM NODES ARE SEARCHED FOR IN THE FOLLOING RECTANGLE
X1=-6;                  %LOWER LIMIT ON THE X AXIS  [ft]
X2=6;                   %UPPER LIMIT ON THE X AXIS  [ft]
Y1=40+TREE(1,2);                  %UPPER LIMIT ON THE Y AXIS  [ft]
Y2=2+TREE(1,2);         %LOWER LIMIT ON THE Y AXIS  [ft]
                        %OFFSET FROM THE INITIAL POSITION OF THE CAR SO
                        %THAT IT ALWAYS SEARCHES IN FRONT OF THE VEHICLE
RAND_SPACE=zeros(2,2);  %SCALAR AND OFFSETS [XSCALAR YSCALAR; XOFFEST YOFFSET]
%INITIALIZING RAND_SPACE
RAND_SPACE(1,1)=(X2-X1);    %XSCALAR             [ft]
RAND_SPACE(1,2)=(Y1-Y2);    %YSCALAR             [ft]     
RAND_SPACE(2,1)=X1;         %XOFFSET FROM ZERO   [ft]
RAND_SPACE(2,2)=Y2;         %YOFFSET FROM ZERO   [ft]


while (DONE==0 && FAIL==0)
    NOGOGO=0;
    %ADD A TEMPORARY NODE TO [TREE]
    if (RAND_GO==0)
        TEMP_NODE= ADD_LINEAR(NODE_DIST, TREE, NODES, GOAL);
    else
        TEMP_NODE= ADD_RANDOM(NODE_DIST, TREE, NODES, RAND_SPACE);
    end
    
    %CHECK TO SEE IF FINISHED
    if (TEMP_NODE(1:2) == GOAL(1:2))    
        DONE=1;
    end
    
    %GENERATE A PATH TO THE TEMPORARY NODE
    [PATH,PATH_COUNT] = GET_PATH(TREE, TEMP_NODE, NODE_DIST, VEHICLE,VEHICLE_GEO);

    %CHECK IF IT WAS A GOOD PATH
    if PATH(1,1)>9000
        NOGOGO=1;
        RAND_GO=1;
    else
        %PATH IS GOOD, NOW CHECK FOR COLLISION
        NOGOGO= CHECK_COLLISION(PATH, OBSTACLE, VEHICLE_GEO, ROAD, 0);
    end


    %ADD TEMPORARY NODE TO THE TREE IF IT IS VALID
    if (NOGOGO==0)
        NODES = NODES+ 1;                   %INCREMENT THE NODE COUNTE
        TREE(NODES, :)=TEMP_NODE;           %ADDS THE NODE TO [TREE]            
        RAND_GO=0;                          %STOPS CHECKING RANDOM NODES
    else  %TRY A NEW RANDOM NODE
        RAND_GO=1;
    end

    if (DONE==1)
        FINAL_PATH=PATH;
        
        CONNECTING_NODE=NODES;     %INITIALIZES THE CONNECTION NODE FROM THE GOAL
        FINAL_NODES=0;
    
        while(CONNECTING_NODE>0)
            FINAL_NODES=FINAL_NODES+1;
            FINAL_TREE(FINAL_NODES, :)=TREE(CONNECTING_NODE,1:2);   %MOVES THE PREVIOUS NODE IN THE TREE INTO THE FINAL TREE
            CONNECTING_NODE=TREE(CONNECTING_NODE,3);          %SETS THE NEXT CONNECTING NODE 
        end
        %PLOT THE PATH IN BLUE
        %plot(FINAL_PATH(1:(PATH_COUNT),1), FINAL_PATH(1:(PATH_COUNT),2))
        %axis([-10, 10, -10,50])
        %hold on
        %PLOT THE TREE IN RED
        %plot(FINAL_TREE(1:FINAL_NODES,1),FINAL_TREE(1:FINAL_NODES,2),'R')
        %axis([-10, 10, -10,50])
        %hold off
    end
    
    ITERATIONS=ITERATIONS+1;
    if ITERATIONS>400
        FAIL=1;
    end
end















end