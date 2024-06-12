SELECT public."Resources".name, public."Resources".type, public."Leads".name, 
public."Leads".location 
FROM public."Resources"
LEFT JOIN public."Leads" ON public."Resources".id = public."Leads".resourse_id
WHERE NOT location = 'New York' AND NOT public."Resources".name = 'Fiverr' LIMIT 8

