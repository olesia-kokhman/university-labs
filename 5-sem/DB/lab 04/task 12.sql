SELECT snum, COUNT(cnum) FROM public."Customers"
GROUP BY snum, cnum
HAVING rating > 2
