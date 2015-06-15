# Info on the abbreviations files

## How does it work?
Since there are different ways of how to abbreviate the bible books in the world and how handle the chapter and verses, there needs to be a markup.
There is also the problem of the different canons/and or something missing (eg. the NT in the Tanach) which we want to display.
And there is the problem that we want to display whole different books too.

The Files are seperated by languages.
Eg.: en-US.json for English (US version is standard).
     de-De.json for standart German (Germany).
     de-CH.json for swiss German.

If there is a language which has different standards in different countries in the world, but is missing, then the most common language file is assumed.
Changes can be made in the settings.

All the versions are searchable in the search dialogue and used in the search pattern. In case of discrepancy the language in the settings are used.

## General info
The search engine can read abbreviations in a smart way (only book names). It looks for unknown abbreviaton, even if it is not handled in the language settings. So you can also abbreviate book names from unknown books.

Priority:
1. encoding.
2. language from the setting.
3. Closest book name to abbrevation.
