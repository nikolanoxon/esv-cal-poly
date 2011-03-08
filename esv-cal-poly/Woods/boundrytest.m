function nogogo = boundrytest(VERTS, THETA, LENGTH, WIDTH, PRINT)


%THIS WILL CONTAIN THE VIRTUAL MAP
%USES BOUNDING BOXES TO DETERMINE A COLLISION
%A COLLISION OCCURS WHEN ONE VERTEX IS IN ANOTHER RECTANGLE
%NOW USING AXIS ALIGNED BOUNDING BOXES, QUICKER AND MORE CONSERVATIVE FOR
%TURNS

nogogo=0;
DONE=0;
DIAG=(WIDTH^2+LENGTH^2)^.5;   %THE CORNER TO CORNER LENGTH OF THE VEHICLE, CONSTANT

AABB=zeros(2,2);              %axis aligned bounding box for vehicle
                              %same set up as obstacle
                              
     %SET THE AXIS ALIGNED BOUNDING BOX FOR THE VEHICLE
     if THETA <= 0
         AABB(1,1)= VERTS(1)+LENGTH*sin(THETA);
         AABB(2,1)= VERTS(3);
         AABB(1,2)= VERTS(2);
         AABB(2,2)= VERTS(2)-DIAG;
         
     elseif THETA > 0
         AABB(1,1)= VERTS(1);
         AABB(2,1)= VERTS(3)+LENGTH*sin(THETA);
         AABB(1,2)= VERTS(4);
         AABB(2,2)= VERTS(4)-DIAG;            
     end                              
                            
%OBSTACLE POSITION


%bounding box for obstacle
%OBSTACLE SIZE CURRENTLLY MODELED AS A RECTANGLE
OBSTACLE=zeros(2,2); %OBSTACLE AREA





OX1=-3;  %LEFT BOUNDARY                  %THE OBSTACLE IS DEFINED BY A RECTANCLE
OX2=2;   %RIGHT BOUNDARY                  %THESE VALUES WILL BE COMING FROM SENSORS 
OY1=24;  %UPPER BOUNDARY                 %AND WILL BE SUBJECT TO CHANGE WHEN THE OBSTACLE MOVES
OY2=12;  %LOWER BOUNDARY

%INITIAL POSITION OF OBSTACLE
OBSTACLE(1,1)=OX1;   
OBSTACLE(1,2)=OY1;
OBSTACLE(2,1)=OX2;
OBSTACLE(2,2)=OY2;


%ROAD BOUNDARIES

ROAD=[-5, 5];      %LEFT, RIGHT

%CHECK TO SEE IF THE CAR IS ON THE ROAD
    if VERTS(1)<ROAD(1)%LEFT SIDE
        nogogo=1;
    elseif VERTS(3)>ROAD(2)%RIGHT SIDE
        nogogo=1;
    end

while (nogogo==0  && DONE==0) %&& PRINT==0  
     
     
     if (AABB(1,1) >OBSTACLE(2,1)) %THE VEHICLE IS ON THE LEFT SIDE
         DONE=1;
     elseif AABB(2,1)<OBSTACLE (1,1) %THE VEHICLE IS ON THE RIGHT SIDE
         DONE=1;
     elseif AABB(1,2)<OBSTACLE(2,2) %THE VEHICLE IS BEFORE THE OBSTACLE
         DONE=1;
     elseif AABB(2,2)>OBSTACLE(1,2) %THE VEHICLE IS PAST THE OBSTACLE
         DONE=1;
     else
         nogogo=1;
     end         
    
    
end



if PRINT==1
    
    
    OBSTACLER(1,1)=OX1;
    OBSTACLER(1,2)=OY1;
    OBSTACLER(2,1)=OX2;
    OBSTACLER(2,2)=OY1;
    OBSTACLER(3,1)=OX2;
    OBSTACLER(3,2)=OY2;
    OBSTACLER(4,1)=OX1;
    OBSTACLER(4,2)=OY2;
    OBSTACLER(5,1)=OX1;
    OBSTACLER(5,2)=OY1;
    
    plot(OBSTACLER(1:5,1),OBSTACLER(1:5,2))
    hold on
    
end



end