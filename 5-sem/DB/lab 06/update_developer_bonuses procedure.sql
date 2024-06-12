CREATE OR REPLACE PROCEDURE update_developer_bonuses(project_id INTEGER) 
AS $$
DECLARE 
dev_cursor CURSOR FOR 
	SELECT projects_id, developers_id FROM public."Projects_Developers";
dev_project_id INTEGER;
dev_developers_id INTEGER;
BEGIN
	OPEN dev_cursor;
	LOOP
		FETCH NEXT FROM dev_cursor INTO dev_project_id, dev_developers_id;
		EXIT WHEN NOT FOUND;
		
		IF dev_project_id = project_id THEN
			UPDATE public."Developers"
			SET bonuses = bonuses + 50
			WHERE id = dev_developers_id;
			
			RAISE NOTICE 'Developer bonuses were updated to: %', dev_developers_id;
		END IF;
	END LOOP;
	CLOSE dev_cursor;
END;
$$ LANGUAGE plpgsql;