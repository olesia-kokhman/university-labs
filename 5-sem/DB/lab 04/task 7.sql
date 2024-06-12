SELECT cname, city, rating FROM public."Customers"
WHERE cnum NOT IN (
	SELECT cnum FROM public."Orders"
	WHERE odate >= '2023-01-10')