#include <iostream>
#include <curl/curl.h>
#include <fstream>

size_t write_data(char* ptr, size_t size, size_t nmemb, std::ofstream& fileHandler)
{
    size_t startPos = fileHandler.tellp();
    fileHandler.write(ptr, nmemb);
    size_t currentPos = fileHandler.tellp();
    return currentPos - startPos;
}

int main(int argc, char** argv)
{
    CURL* curl;
    curl = curl_easy_init();

    if (curl)
    {
        std::ofstream file("myFace.omg", std::ios::binary | std::ios::app);

        const std::string url("https://avatars.githubusercontent.com/u/15244432?v=4");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);

        CURLcode curlResponse;
        curlResponse = curl_easy_perform(curl);
        std::cout << "Curl response code: " << curlResponse << std::endl;

        long httpResponseCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpResponseCode);
        std::cout << "Http response: " << httpResponseCode << std::endl;

        curl_easy_cleanup(curl);
    }
    else
    {
        std::cout << "cannot init curl." << std::endl;
    }
    return 0;
}