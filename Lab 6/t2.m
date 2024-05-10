g1=tf([1],[1 1]);
g2=tf([1],[1 1]);
g3=tf([1],[1 1]);
g4=tf([1],[1 1]);
g5=tf([1],[1 1]);
g6=tf([1],[1 1]);
g7=tf([1],[1 1]);
g1.outputname='f';g1.inputname='e';
g2.outputname='b';g2.inputname='a';
g3.outputname='o';g3.inputname='a';
g4.outputname='d';g4.inputname='a';
g5.outputname='g';g5.inputname='e';
g6.outputname='c';g6.inputname='h';
g7.outputname='k';g7.inputname='c';
sum1=sumblk('a','r','f','k','+--');
sum2=sumblk('e','b','o','++');
sum3=sumblk('i','o','d','++');
sum4=sumblk('h','c','i','g','-++');

hold on
plot(task2Atest1)