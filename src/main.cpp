#include <iostream>
#include <curl/curl.h>
#include <fstream>

size_t write_data(char* ptr, size_t size, size_t nmemb, std::string& htmlResponse)
{
    htmlResponse.append(ptr);
    return htmlResponse.length();
}

bool executeHttpQuery(std::string url, const std::string& path, std::string* htmlResponse)
{
    CURL* curl;
    curl = curl_easy_init();
    CURLcode curlResponse;
    long httpResponseCode = 0;

    if (curl)
    {
        url.append(path);

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlResponse);

        curlResponse = curl_easy_perform(curl);
        std::cout << "Curl response code: " << curlResponse << std::endl;

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpResponseCode);
        std::cout << "Http response: " << httpResponseCode << std::endl;

        curl_easy_cleanup(curl);
    }
    else
    {
        std::cout << "cannot init curl." << std::endl;
        return false;
    }

    return httpResponseCode == 200 && curlResponse == CURLE_OK;
}

int main(int argc, char** argv)
{

    std::string url("https://en.pons.com/translate/german-polish/");

    std::string command = "";
    while(command != "exit")
    {
        command.clear();
        std::cin >> command;
        if(command.starts_with("download "))
        {
            std::string path = command.substr(9);
            std::string htmlDocumentResponse;
            if(executeHttpQuery(url, path, &htmlDocumentResponse))
            {
                if(htmlDocumentResponse.find("rom first") != std::string::npos)
                {
                    std::cout << "founded!" << std::endl;
                }
            }
        }
    }


    return 0;
}
