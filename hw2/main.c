#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <cJSON.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  size_t total_size = size * nmemb;
  strncat((char *)userdata, (char *)ptr, total_size);
  return total_size;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <city>\n", argv[0]);
    return 1;
  }

  char url[65536] = {0};

  snprintf(url, sizeof(url), "https://en.wttr.in/%s?format=j1", argv[1]);

  char errbuf[CURL_ERROR_SIZE] = {0};

  CURL *curl = curl_easy_init();
  char json[65536] = {0};
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, json);
  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  if (*errbuf != 0){
    printf("There was an error completing request, please try again later\n");
    printf("Error: %s\n", errbuf);
    return 1;
  }

  if (json[0] == '<'){
    printf("Couldn't find needed location, are you sure that location '%s' exists?\n", argv[1]);
    return 1;
  }

  cJSON *parse = cJSON_Parse(json);

  cJSON *nearest_area = cJSON_GetArrayItem(cJSON_GetObjectItem(parse, "nearest_area"), 0);
  cJSON *region = cJSON_GetArrayItem(cJSON_GetObjectItem(nearest_area, "region"), 0);
  cJSON *value = cJSON_GetObjectItem(region, "value");
  printf("You chose: %s\n", value->valuestring);

  cJSON *weather = cJSON_GetArrayItem(cJSON_GetObjectItem(parse, "weather"), 0);
  cJSON *max_temp = cJSON_GetObjectItem(weather, "maxtempC");
  cJSON *min_temp = cJSON_GetObjectItem(weather, "mintempC");

  printf("Max temperature: %s\n", max_temp->valuestring);
  printf("Min temperature: %s\n", min_temp->valuestring);

  cJSON *current = cJSON_GetArrayItem(cJSON_GetObjectItem(parse, "current_condition"), 0);
  cJSON *wind_dir = cJSON_GetObjectItem(current, "winddir16Point");
  cJSON *wind_speed = cJSON_GetObjectItem(current, "windspeedKmph");
  printf("Wind direction: %s\n", wind_dir->valuestring);
  printf("Wind speed: %s km/h\n", wind_speed->valuestring);

  cJSON *weather_desc = cJSON_GetArrayItem(cJSON_GetObjectItem(current, "weatherDesc"), 0);
  cJSON *weather_desc_0 = cJSON_GetArrayItem(weather_desc, 0);
  printf("Current weather: %s\n", weather_desc_0->valuestring);

  return 0;
}
