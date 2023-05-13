//fpc 2.6.2

program UCLN;
uses crt;
function ucln(x,y:integer):integer;
begin
if x = y then ucln:=x
else if x > y then ucln:=ucln(x mod y,y)
else ucln:=ucln(x, y mod x);
end;
var x,y:integer;

begin
write('nhap x,y:');
readln(x,y);
write('Uoc chung lon nhat la: ', ucln(x,y));
readln;
end.
