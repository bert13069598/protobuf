#include <iostream>
#include "bbox.pb.h"
#define STRING 0

using namespace std;
using namespace detection;

int main() {
    BboxList bboxList;
    {
        Bbox *bbox = bboxList.add_bboxes();
        bbox->set_cls(1);
        bbox->set_prob(0.85);
        bbox->set_x(0.55);
        bbox->set_y(0.48);
        bbox->set_w(0.36);
        bbox->set_h(0.14);
    }
    {
        Bbox *bbox = bboxList.add_bboxes();
        bbox->set_cls(2);
        bbox->set_prob(0.54);
        bbox->set_x(0.74);
        bbox->set_y(0.24);
        bbox->set_w(0.46);
        bbox->set_h(0.67);
    }
    {
        Bbox *bbox = bboxList.add_bboxes();
        bbox->set_cls(3);
        bbox->set_prob(0.97);
        bbox->set_x(0.34);
        bbox->set_y(0.57);
        bbox->set_w(0.26);
        bbox->set_h(0.35);
    }
    // Encoding
    const int size = bboxList.ByteSizeLong();
    uint8_t* buffer = new uint8_t[size];
#if STRING
    std::string serialized_data;
    bboxList.SerializeToString(&serialized_data);
    cout << serialized_data << endl;
#else
    bboxList.SerializeToArray(buffer, size);
    cout << buffer << endl;
#endif

    // Decoding
    BboxList decoded_bboxList;
#if STRING
    if (decoded_bboxList.ParseFromString(serialized_data)) {
#else
    if (decoded_bboxList.ParseFromArray(buffer, size)) {
#endif
        for (const Bbox& bbox : decoded_bboxList.bboxes()) {
            cout << "cls  : " << bbox.cls() << endl;
            cout << "prob : " << bbox.prob() << endl;
            cout << "x    : " << bbox.x() << endl;
            cout << "y    : " << bbox.y() << endl;
            cout << "w    : " << bbox.w() << endl;
            cout << "h    : " << bbox.h() << endl;
        }
    } else {
        cerr << "Failed to parse serialized data." << endl;
    }
    delete[] buffer;

    return 0;
}
