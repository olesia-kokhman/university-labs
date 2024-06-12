SELECT public."Leads".name, UPPER(public."Leads".location), public."Projects".name, 
public."Projects".budget
FROM public."Leads"
LEFT JOIN public."Projects" ON public."Leads".id = public."Projects".lead_id
WHERE location LIKE 'Miami%'
ORDER BY budget DESC
