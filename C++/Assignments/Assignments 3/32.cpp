#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

class Texture{
private :
    string name;
    int width;
    int height;

public :
        Texture(string n,int w,int h) : name(n), width(w), height(h) {
            cout <<"load msg" << endl;
        }

        ~Texture() {
            cout << "object is destroy"<< endl;
        }

        void display() const {
            cout << "name : " << name << "width : " << width << "height : " << height << endl;
}

};

class Shader {
private :
            string name;
            string type;

public :
            Shader(string n, string  t) : name(n), type(t) {
                cout << "compilation " << endl;
            }

            ~Shader(){
                cout << "destruction " << endl;
            }
};

class AudioClip {
private:
    string name;
    double duration;

public:
    AudioClip(string n, double d) : name(n), duration(d) {
        cout << "Audio Loaded: " << name  << endl;
    }

    ~AudioClip() {
        cout << "Audio Destroyed: " << name << endl;
    }

    string getName() const {
        return name;
    }
};


int main() {

    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    // 2. Call display()
    tex1->display();

    // unique_ptr<Texture> tex2 = tex1; 

    unique_ptr<Texture> tex2 = move(tex1);

    // Verify tex1 is null
    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;

    auto shader = make_shared<Shader>("main_ vertex", "vertext");
        cout << "ref : " << shader.use_count() << endl;
        {
            auto sharedsahd = shader;
            cout << "ref : " << shader.use_count() << endl;

            auto editorref = shader;
            cout << "ref : " << shader.use_count() << endl;

        }
    
            cout << "ref : " << shader.use_count() << endl;


        auto Audio = make_shared<AudioClip>("explosion", 2.5);
        weak_ptr<AudioClip> observer = Audio;

        if(auto clip = observer.lock()) {
            cout << "clip is alive : " << clip->getName() << endl;
        }

        Audio.reset();

        if(observer.expired()){
            cout << "clip is already uploded"<< endl;
        }



        return 0;
}