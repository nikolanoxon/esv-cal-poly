function nogogo=testroute(TREE, TEMP_NODE, NODE_DIST, DONE)


ROUTE_COUNT=0;            %NUMBER OF NODES IN THE ROUTE TO BE TESTED
ROUTE_TREE=zeros(500,2);  %STORES THE NODES IN THE TESTED ROUTE [x,y]
PATH=zeros(500,3);        %PATH TAKEN [x,y,theta]
CENTER=[0,0];             %CENTER OF THE RADIUS OF CURVATURE
CURRENT_POSITION=[0,0,0]; %CURRENT POSITION OF THE FOLLOW [x,y,theta]

SIGMA=0;                  %TURN ANGLE OF THE FRONT WHEELS
THETA=0;                  %ANGLE OF THE CAR
PHI=0;                    %ARC ANGLE
NU=0;                     %LOOKAHEAD ANGLE
DELTA=0;                  %REQUIRED STEER ANGLE
Lfw=0;                    %LOOKAHEAD DISTANCE
RADIUS=0;                 %RADIUS OF CURVATURE
DIV_LOOK=8;               %NUMBER OF DIVISIONS TO LOOKAHEAD
DIV=4;                    %NUMBER OF DIVISIONS PER TREE SEGMENT

TESTS=0;                  %NUMBER OF TESTS REQUIRED
VERTS=zeros(400,4);       %VERTICIES OR THE VEHICLE [x,y,x,y], LEFT SIDE, RIGHT SIDE
nogogo=0;                 %FLAG TO DETERMINE PATH FEASIBILITY
CENTERS=zeros(60,2);
TIP=[0,0];                    %CENTER OF FRONT OF THE VEHICLE [x,y]
LENGTH=2;                 %LENGTH OF THE VEHICLE
WIDTH=.5;                %WIDTH OF THE VEHICLE

%WORK THE ROUTE BACKWARDS

%EXTRACT THE COMPLETED PATH************************************************
CONNECTING_NODE=TEMP_NODE(3);     %INITIALIZES THE CONNECTION NODE FROM THE TEMP NODE
ROUTE_TREE(1,:)=TEMP_NODE(1:2);
ROUTE_COUNT=1;

while(CONNECTING_NODE>0)
    for i=1:1:(DIV-1)      %divides up each node length
        ROUTE_COUNT=ROUTE_COUNT+1;
        ROUTE_TREE(ROUTE_COUNT,1)=ROUTE_TREE(ROUTE_COUNT-1,1)-(1/DIV)*(ROUTE_TREE(ROUTE_COUNT-1,1)-TREE(CONNECTING_NODE,1));
        ROUTE_TREE(ROUTE_COUNT,2)=ROUTE_TREE(ROUTE_COUNT-1,2)-(1/DIV)*(ROUTE_TREE(ROUTE_COUNT-1,2)-TREE(CONNECTING_NODE,2));
        
    end
    ROUTE_COUNT=ROUTE_COUNT+1;
    ROUTE_TREE(ROUTE_COUNT, :)=TREE(CONNECTING_NODE,1:2);   %MOVES THE PREVIOUS NODE IN THE TREE INTO THE FINAL TREE
    CONNECTING_NODE=TREE(CONNECTING_NODE,3);          %SETS THE NEXT CONNECTING NODE 
    
end

%TESTS=ROUTE_COUNT-DIV;
CURRENT_POSITION=PATH(1,:);
NN=1;
%CC=ROUTE_COUNT;

cccc=0;
CC=ROUTE_COUNT;
TESTS=ROUTE_COUNT-DIV_LOOK;


%initial position of the vehicle
PATH(1,:)=TREE(1,:);

%CALCULATE VERTICIES OF THE VEHICLE
        THETA=PATH(NN,3);
        %LOCATION OF THE FRONT CENTER
        TIP(1)=-LENGTH*sin(THETA)+PATH(NN,1);  
        TIP(2)=LENGTH*cos(THETA)+PATH(NN,2);
        %CALCULATE THE LEFT CORNER
        VERTS(NN,1)=TIP(1)-(WIDTH/2)*cos(THETA);
        VERTS(NN,2)=TIP(2)-(WIDTH/2)*sin(THETA);
        %CALCULATE THE RIGHT CORNER
        VERTS(NN,3)=TIP(1)+(WIDTH/2)*cos(THETA);
        VERTS(NN,4)=TIP(2)+(WIDTH/2)*sin(THETA);
        

for i=TESTS:(-1):1
    if  (nogogo==0)
        
      
        Lfw=((PATH(NN,1)-ROUTE_TREE(CC-DIV_LOOK,1))^2+(PATH(NN,2)-ROUTE_TREE(CC-DIV_LOOK,2))^2)^.5;
        NU=atan((PATH(NN,1)-ROUTE_TREE(CC-DIV_LOOK,1))/(PATH(NN,2)-ROUTE_TREE(CC-DIV_LOOK,2)))-PATH(NN,3);
        CC=CC-1;
    
    
        if NU==0
            RADIUS=0;
            PATH(NN+1,1)=ROUTE_TREE(CC,1);
            PATH(NN+1,2)=ROUTE_TREE(CC,2);
            NN=NN+1;
        else
            RADIUS=Lfw/(2*sin(NU));
            SIGMA = atan(LENGTH*sin(NU)/(Lfw/2));
            
            
            %TEST FEASIBILITY OF TURN ANGLE
            if (abs(SIGMA)>.75)&& (DONE==0)
                nogogo=1;
            end
            
            THETA=PATH(NN,3);
%             if (abs(RADIUS)<1) && (DONE==0) && (abs(RADIUS) >0)
%                 nogogo=1;
%             end
            %LOCATE THE CENTER OF THE TURN 
            CENTER(1)=PATH(NN,1)+RADIUS*cos(PATH(NN,3));  %X
            CENTER(2)=PATH(NN,2)+RADIUS*sin(PATH(NN,3));  %Y
            
        
    
            PHI=-2*NU;
            NN=NN+1;
            %ADD NEXT NODE TO THE TREE [x,y,theta]
            PATH(NN,1)=CENTER(1)-RADIUS*cos(THETA+PHI/DIV);
            PATH(NN,2)=CENTER(2)-RADIUS*sin(THETA+PHI/DIV);
            PATH(NN,3)=PHI/DIV-THETA;
            
            
            if PATH(NN,2)<=PATH((NN-1),2)
                    nogogo=1;
            end
            if abs(PATH(NN,3)-PATH((NN-1),3))>1.2
                    nogogo=1;
            end
            
            
        end
        
        %CALCULATE VERTICIES OF THE VEHICLE
        THETA=PATH(NN,3);
        %LOCATION OF THE FRONT CENTER
        TIP(1)=-LENGTH*sin(THETA)+PATH(NN,1);  
        TIP(2)=LENGTH*cos(THETA)+PATH(NN,2);
        %CALCULATE THE LEFT CORNER
        VERTS(NN,1)=TIP(1)-(WIDTH/2)*cos(THETA);
        VERTS(NN,2)=TIP(2)-(WIDTH/2)*sin(THETA);
        %CALCULATE THE RIGHT CORNER
        VERTS(NN,3)=TIP(1)+(WIDTH/2)*cos(THETA);
        VERTS(NN,4)=TIP(2)+(WIDTH/2)*sin(THETA);
        
        if nogogo==0
            
            nogogo = boundrytest(VERTS(NN,:), THETA, LENGTH, WIDTH, 0);
        end
    end
end

if (DONE==1)
boundrytest(VERTS(NN,:), THETA, LENGTH, WIDTH, 1);
plot(ROUTE_TREE(1:ROUTE_COUNT,1),ROUTE_TREE(1:ROUTE_COUNT,2))
hold on
plot(PATH(1:NN,1),PATH(1:NN,2),'R')
hold on
plot(VERTS(1:NN,1),VERTS(1:NN,2), 'G')
hold on
plot(VERTS(1:NN,3),VERTS(1:NN,4), 'G')
hold on
end


end