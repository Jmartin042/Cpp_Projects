x=[0,1,2.1,3.1,4.2];
y=[
1,3.1,5.2,6.9,9.1];
coef=polyfit(x,y,1);
m=coef(1);
b=coef(2);
Y=m*x+b;
matlab_error=sum((y - Y).^2);
fid=fopen('output_7.txt','a');
fprintf(fid,'*** RESULT FROM MATLAB\n');
fprintf(fid,'*** THE MATCHING FUNCTION IS Y=(%.3f) * X +(%.3f) \n',m,b);
fprintf(fid,'*** THE ERROR FROM MATLAB IS %.3f \n', matlab_error);
