function nogogo = CHECK_COLLISION(PATH, OBSTACLE, VEHICLE_GEO, ROAD, PRINT)

NN=1;
WIDTH=VEHICLE_GEO(2);
LENGTH=VEHICLE_GEO(1);
V_OBSTACLE=OBSTACLE(5);      %VELOCITY OF OBSTCLAE [ft/s]
nogogo=0;
DONE=0;
KARTER=zeros(5,2);
OBSTACLEB=zeros(2,2);
BUFFER=.25;

%OBSTACLE STUFF
%EASY MODE
%CENTER
CENTER_POS=OBSTACLE(1:2);   %[x,y]
O_HIT=OBSTACLE(3);             %HEIGHT[ft]
O_WIT=OBSTACLE(4);             %WIDTH [ft]

%INITIAL POSITION
OX1=CENTER_POS(1)-O_WIT/2;  %LEFT BOUNDARY   %THE OBSTACLE IS DEFINED BY A RECTANCLE
OX2=CENTER_POS(1)+O_WIT/2;   %RIGHT BOUNDARY %THESE VALUES WILL BE COMING FROM SENSORS 
OY1=CENTER_POS(2)+O_HIT/2;  %UPPER BOUNDARY                 %AND WILL BE SUBJECT TO CHANGE WHEN THE OBSTACLE MOVES
OY2=CENTER_POS(2)-O_HIT/2;  %LOWER BOUNDARY





%THE CORNER TO CORNER LENGTH OF THE VEHICLE, CONSTANT
DIAG=(VEHICLE_GEO(2)^2+VEHICLE_GEO(1)^2)^.5;   

while (PATH(NN+1,5)>0 && nogogo==0)
    
    NN=NN+1;
    %CALCULATE VERTICIES OF THE VEHICLE
    THETA=PATH(NN,3);
    %LOCATION OF THE FRONT CENTER
    TIP(1)=-LENGTH*sin(THETA)+PATH(NN,1);  
    TIP(2)=LENGTH*cos(THETA)+PATH(NN,2);
    %CALCULATE THE LEFT CORNER
    VERTS(1)=TIP(1)-(WIDTH/2)*cos(THETA);
    VERTS(2)=TIP(2)-(WIDTH/2)*sin(THETA);
    %CALCULATE THE RIGHT CORNER
    VERTS(3)=TIP(1)+(WIDTH/2)*cos(THETA);
    VERTS(4)=TIP(2)+(WIDTH/2)*sin(THETA);

    AABB=zeros(2,2);              %axis aligned bounding box for vehicle
                              %same set up as obstacle                       
    %SET THE AXIS ALIGNED BOUNDING BOX FOR THE VEHICLE
    if THETA <= 0
         AABB(1,1)= VERTS(1)+VEHICLE_GEO(1)*sin(THETA)-BUFFER; %left side x
         AABB(1,2)= VERTS(2)+BUFFER;                   %left side y
         AABB(2,1)= VERTS(3)+BUFFER;                   %right side x
         AABB(2,2)= VERTS(2)-DIAG-BUFFER;              %right side y
         
    elseif THETA > 0
         AABB(1,1)= VERTS(1)-BUFFER;                   %same layout as above
         AABB(1,2)= VERTS(4)+BUFFER;
         AABB(2,1)= VERTS(3)+LENGTH*sin(THETA)+BUFFER;
         AABB(2,2)= VERTS(4)-DIAG-BUFFER;            
    end                              
 

    
    %CHECK TO SEE IF THE CAR IS ON THE ROAD
    if VERTS(1)<ROAD(1)%LEFT SIDE
        nogogo=1;
    elseif VERTS(3)>ROAD(2)%RIGHT SIDE
        nogogo=1;
    end
     
    TIME_TOT=PATH(NN,5);
    
    %SET THE OBSTACLE BOUNDING BOX
    OBSTACLEB(1,1)=OX1+V_OBSTACLE*TIME_TOT;   %LEFT SIDE X
    OBSTACLEB(1,2)=OY1;   %LEFT SIDE Y
    OBSTACLEB(2,1)=OX2+V_OBSTACLE*TIME_TOT;   %RIGHT SIDE X
    OBSTACLEB(2,2)=OY2;   %RIGHT SIDE Y

    
    %CHECK COLLISION WITH OBSTACLE
    if (nogogo==0) %&& PRINT==0  
          
        if (AABB(1,1) >OBSTACLEB(2,1)) %THE VEHICLE IS ON THE LEFT SIDE
            DONE=1;
        elseif AABB(2,1)<OBSTACLEB(1,1) %THE VEHICLE IS ON THE RIGHT SIDE
            DONE=1;
        elseif AABB(1,2)<OBSTACLEB(2,2) %THE VEHICLE IS BEFORE THE OBSTACLE
            DONE=1;
        elseif AABB(2,2)>OBSTACLEB(1,2) %THE VEHICLE IS PAST THE OBSTACLE
            DONE=1;
        else
            nogogo=1;
        end         
    
    
    end

end

% if PRINT==1
%     
% 
%     %ORGANIZE THE VERTICIES OF THE OBSTACLE
%     OBSTACLER(1,:)=OBSTACLE(1,:);   %FRONT LEFT CORNER
%     OBSTACLER(2,1)=OBSTACLE(2,1);   %FRONT RIGHT CORNER X
%     OBSTACLER(2,2)=OBSTACLE(1,2);   %FRONT RIGHT CORNER Y
%     OBSTACLER(3,:)=OBSTACLE(2,:);   %REAR RIGHT CORNER
%     OBSTACLER(4,1)=OBSTACLE(1,1);   %REAR LEFT CORNER X
%     OBSTACLER(4,2)=OBSTACLE(2,2);   %REAR LEFT CORNER Y
%     OBSTACLER(5,:)=OBSTACLE(1,:);   %FRONT LEFT CORNER
%     
%     %PLOT THE OBSTACLE
%     %axis([-4, 4, 0, 40]);
%     plot(OBSTACLER(1:5,1),OBSTACLER(1:5,2))
%     hold on
%     
%     %ORGANIZE THE VERTICIES OF THE VEHICLE
%     %FRONT
%     KARTER(1,:)=VERTS(1,1:2);      %FRONT LEFT CORNER
%     KARTER(2,:)=VERTS(1,3:4);      %FRONT RIGHT CORNER
%     KARTER(5,:)=VERTS(1,1:2);      %FRONT LEFT CORNER
%     %REAR
%     if (THETA>=0)    
%         KARTER(3,1)=AABB(2,1);                 %REAR RIGHT CORNER X
%         KARTER(3,2)=AABB(2,2)+WIDTH*sin(THETA);%REAR RIGHT CORNER Y
%         KARTER(4,1)=AABB(2,1)-WIDTH*cos(THETA);%REAR LEFT CORNER X
%         KARTER(4,2)=AABB(2,2);                 %REAR LEFT CORNER Y
%     elseif (THETA<0)
%         KARTER(3,1)=AABB(1,1)+WIDTH*cos(THETA);%REAR RIGHT CORNER X
%         KARTER(3,2)=AABB(2,2);                 %REAR RIGHT CORNER Y
%         KARTER(4,1)=AABB(1,1);                 %REAR LEFT CORNER X
%         KARTER(4,2)=AABB(2,2)-WIDTH*sin(THETA);%REAR LEFT CORNER Y
%     end
%     
%     %PLOT THE VEHICLE
%     plot(KARTER(1:5,1),KARTER(1:5,2))
%     %FRAMES=getframe(Figure(1));
%     axis([-6,6,-5,40])
%     hold off
%     
%     
% end



end
