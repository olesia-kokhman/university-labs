SELECT snum, cname,
COUNT(cnum)
FROM public."Customers"
GROUP BY snum