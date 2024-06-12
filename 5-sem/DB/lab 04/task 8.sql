SELECT cname, city, rating FROM public."Customers"
WHERE snum NOT IN(
	SELECT snum FROM public."Salers"
	WHERE sname = 'John Doe' OR comm > 0.07)
UNION
SELECT cname, city, rating FROM public."Customers"
WHERE cnum NOT IN(
	SELECT cnum FROM public."Orders"
	WHERE odate >= '2023-01-10');
