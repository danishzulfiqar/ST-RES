clf

numgh = (1);                
dengh = poly([0 -3 -4 -8]); 
GH=tf(numgh,dengh);       
rlocus(GH)               
z=0.2:0.05:0.5;           
                         
wn=0:1:10;                
                       
sgrid(z,wn)              
title ('Root Locus')      

pause
rlocus(GH)                
axis([-2 0 -2 2])         
title('Close-up')         
z=0.591;                 
                    
wn=0;                     
                        
sgrid(z,wn)               
                          
for k=1: 3                
                          
[K,p]=rlocfind(GH) ;      
                          
                      
end                    
