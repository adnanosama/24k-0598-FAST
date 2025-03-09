#include <iostream>
#include <string>
using namespace std;


class MediaFile{
    string filepath;
    float size;
    public:
    MediaFile(){
        filepath = "";
        size = 0;
    }
    MediaFile(string filepath, float size){
        this->filepath = filepath;
        this->size = size;
    }
    string getFilePath(){
        return filepath;
    }
    float getSize(){
        return size;
    }
    virtual void play(){
        cout << "Playing " << filepath << endl;
    }
    virtual void stop(){
        cout << "Stopped " << filepath << endl;
    }

};

class VisualMedia: virtual public MediaFile{
    string resolution;
    public:
    VisualMedia(string resolution){
        this->resolution = resolution;
    }
    string getResolution(){
        return resolution;
    }
    void play() override {
        MediaFile::play();
        cout << "Playing video at resolution: " << resolution << endl;
    }
    void stop() override {
        MediaFile::stop();
        cout << "Stopped video" << endl;
    }
};

class AudioMedia: virtual public MediaFile{
    float sampleRate;
    public:
    AudioMedia(float sampleRate) {
        this->sampleRate = sampleRate;
    }
    float getSampleRate(){
        return sampleRate;
    }
    void play() override {
        MediaFile::play();
        cout << "Playing audio at sample rate: " << sampleRate << " Hz" << endl;
    }
    void stop() override{
        MediaFile::stop();
        cout << "Stopped audio" << endl;
    }
};

class Videofile: public VisualMedia, public AudioMedia{
        public:
        Videofile(string resolution, float sampleRate): VisualMedia(resolution), AudioMedia(sampleRate){
    }
    void play() override {
        VisualMedia::play();
        AudioMedia::play();
    }
    void stop() override {
        VisualMedia::stop();
        AudioMedia::stop();
    }
};

int main(){
    MediaFile m1("C:/Users/Downloads/Video.mp4", 1024);
    m1.play();
    m1.stop();
    cout << endl;

    VisualMedia v1("1920x1080");
    v1.play();
    v1.stop();
    cout << endl;

    AudioMedia a1(44100);
    a1.play();
    a1.stop();
    cout << endl;

    Videofile vf1("1920x1080", 44100);
    vf1.play();
    vf1.stop();
    cout << endl;
    getchar();
    return 0;
}