// Given a bunch of text like "/* This is a comment string Hello  \n all */", print the stuff between the opening and closing comment characters, including the new line: a Facebook interview problem

#include <stdio.h>
#include <stdint.h>
#include <string>

using std::string;

const string testString = string("hello /* this is a\nmulti line\n comment */ all \n the kings /* grand old */ men");
const string COMMENT_START = string("/*");
const string COMMENT_END = string("*/");
const string NEW_LINE = string("\n");

string RemoveComments(string inString)
{
    string retString;
    size_t commentStart = inString.find(COMMENT_START); //index of start of comment char
    size_t commentEnd = inString.rfind(COMMENT_END) + 2; //index of end of comment char
    size_t idx = 0;
    size_t newLineIdx = 0;
    uint32_t newLineCnt = 0;

    //Find all new lines within comment block
    newLineIdx = inString.find_first_of(NEW_LINE);
    while(newLineIdx < commentEnd && newLineIdx != string::npos)
    {
        if(newLineIdx > commentStart)
        {
            newLineCnt++;
        }
        newLineIdx = inString.find_first_of(NEW_LINE, newLineIdx+1);
    }

    retString.append(inString.substr(0, commentStart));

    for(uint32_t ctr = 0; ctr < newLineCnt; ctr++) 
    {
        retString.append(NEW_LINE);
    }

    retString.append(inString.substr(commentEnd, inString.size() - (commentEnd)));
    return retString;
}

int main(int argc, char *argv[])
{
    string noComments = RemoveComments(testString);
    printf("Removing comment from:\n\"%s\"\n\n", testString.c_str());

    printf("Result string:\n\"%s\"\n", noComments.c_str());

    return 0;
}
