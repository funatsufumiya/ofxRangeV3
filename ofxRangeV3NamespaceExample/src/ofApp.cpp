#include "ofxRangeV3.h"

// to avoid conflict with std::ranges (because oF auto insert `using namespace std;`)
namespace ranges_v3 = ::ranges;

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup() {
        {
            std::vector<int> xs{5, 4, 3, 2, 1};

            ranges_v3::sort(xs);
            ranges_v3::for_each(xs, [] (int x) {
                std::cout << x << std::endl;
            });
        }
        {
            std::vector<int> xs = ranges_v3::view::ints(1, 6) | ranges_v3::view::transform([] (int x) {
                return x * x;
            });
            ranges_v3::for_each(xs, [] (int x) {
                std::cout << x << std::endl;
            });
        }
    }
    void update() {}
    void draw() {}
    void exit() {}
    
    void keyPressed(int key) {}
    void keyReleased(int key) {}
    void mouseMoved(int x, int y ) {}
    void mouseDragged(int x, int y, int button) {}
    void mousePressed(int x, int y, int button) {}
    void mouseReleased(int x, int y, int button) {}
    void mouseEntered(int x, int y) {}
    void mouseExited(int x, int y) {}
    void windowResized(int w, int h) {}
    void dragEvent(ofDragInfo dragInfo) {}
    void gotMessage(ofMessage msg) {}
};

int main() {
    ofGLFWWindowSettings setting;
#if 10 <= OF_VERSION_MINOR
    setting.setSize(1280, 720);
#else
    setting.width = 1280;
    setting.height = 720;
#endif
    auto window = ofCreateWindow(setting);
    auto app = std::make_shared<ofApp>();
    ofRunApp(window, app);
    ofRunMainLoop();
}
