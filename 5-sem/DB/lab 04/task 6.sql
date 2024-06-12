SELECT cname, city, rating, snum FROM public."Customers"
WHERE snum NOT IN (
SELECT snum FROM public."Salers"
WHERE sname = 'John Doe' OR comm > 0.07) 