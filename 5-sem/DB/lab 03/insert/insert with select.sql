INSERT INTO public."Leads"(
	id, name, location, status, resourse_id, created_at, connected_at)
SELECT 55, 'Jerry Frek', location, status, 4, created_at, connected_at
FROM public."Leads"
Where id = 51