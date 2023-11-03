#include "shell.h"
/**
 * ogo_getenv - dan and mav custom getenv function that would be used
 * to get the current enviroment of my shell.
 * @enviro: this represents the enviroment to be gotten as an argument.
 * Return: on sucess it returns the environment, else NULL.
 */

char *ogo_getenv(char *enviro)
{
	char **env,  *ent_env;

	size_t ln;

	ln = 0;

	if (enviro == NULL)
	{
		return (NULL);
	}

	for (env = environ; *env != NULL; env++)
	{
		ent_env = *env;

		ln = _strlen(enviro);

		if (ogo_strncmp(ent_env, enviro, ln) == 0 && ent_env[ln] == '=')
		{
			return (&ent_env[ln + 1]);
		}
	}

	return (NULL);
}

