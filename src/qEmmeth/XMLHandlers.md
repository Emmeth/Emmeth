# Description how to handle the XML Files

## How it works
Reads the xml file in a specific way to display it.
Every xml file needs to be based on a specific validation file (xsd). It need to have the filename based on the xml schema.
The xml syntax is read through a

Eg.: Tanach-xml has various book files. The folder for the xml files needs to have the same name as the schema. (tanach-xml\).
     Tanach-xml needs a validation file in xsd format (tanach-xml.xsd). To check if the file in the folder is an actual tanach-xml file or something else.
     Tanach-xml needs a json file with the same schema name (tanach-xml.json), to read an process the content correctly.

Folder:
    xml -> validation file
        -> json
            ->precessing.

## Structure of the json file
   Xml-tag : operation

## Operations
Usage on how to handle the XML tags.

* ignore - ignores the tag.
* important
* read - simply reads the tag and displays the content/children in the XMLReader.
* desc - reads the content and displays it in the File Description.
* encoding - important for the file encoding.
* abbrev - is used for the book abbreviation (searchable).
* chapter - displays the whole chapter.
* word - the simple word to display.
* verse - displays the whole verse.
* value - a numerical value (usally an attribute).
* attrib - a simple attribute (usally text).
* link - URL link.
* folder - all the necessary books are in a folder.
* single - all the necessary books are in the same file.
