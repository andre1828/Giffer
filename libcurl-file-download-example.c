#include <stdio.h>
#include <curl/curl.h>


int main(int argc, char const *argv[])
{

    CURL *curl = curl_easy_init();

    FILE *fp;
    CURLcode res;
    char *fileName = "downloaded-kermit-dance.gif";

    fp = fopen(fileName, "wb");
    curl_easy_setopt(curl, CURLOPT_URL, "https://c.tenor.com/PEiwJfiuGkAAAAAd/kermit-dance.gif");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

    curl_easy_cleanup(curl);
    fclose(fp);
    return 0;
}