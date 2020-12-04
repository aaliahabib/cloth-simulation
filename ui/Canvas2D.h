#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <memory>

#include "Brush.h"
#include "Settings.h"

#include "shapes/ImplicitShape.h"
#include "SupportCanvas2D.h"
#include "CS123SceneData.h"

class RayScene;

class Camera;

/**
 * @class Canvas2D
 *
 * 2D canvas that students will implement in the Brush and Filter assignments. The same canvas
 * will be used to display raytraced images in the Intersect and Ray assignments.
 */
class Canvas2D : public SupportCanvas2D {
    Q_OBJECT
public:
    Canvas2D();
    virtual ~Canvas2D();

    void setScene(RayScene *scene);

    // UI will call this from the button on the "Ray" dock
    void renderImage(Camera *camera, int width, int height);

    // This will be called when the settings have changed
    virtual void settingsChanged();

    QImage* getImage() { return m_image; }


public slots:
    // UI will call this from the button on the "Ray" dock
    void cancelRender();

    // UI will call this from the button on the "Filter" dock
    void filterImage();

protected:
    virtual void paintEvent(QPaintEvent *);  // Overridden from SupportCanvas2D.
    virtual void mouseDown(int x, int y);    // Called when left mouse button is pressed on canvas
    virtual void mouseDragged(int x, int y); // Called when left mouse button is dragged on canvas
    virtual void mouseUp(int x, int y);      // Called when left mouse button is released

    // Called when the size of the canvas has been changed
    virtual void notifySizeChanged(int w, int h);



private:
    int checkIntersection(glm::vec4 p, glm::vec4 d, float &outT);
    glm::vec4 computePhongLighting(glm::vec4 pt, glm::vec4 viewPt, glm::vec4 normal, const CS123SceneMaterial &material, glm::vec4 texture);
    glm::vec4 rayTrace(int objIndex, float t, glm::vec4 p, glm::vec4 d, glm::vec4 eye, int depth);

    std::unique_ptr<RayScene> m_rayScene;

    //TODO: [BRUSH, INTERSECT, RAY] Put your member variables here.
    std::unique_ptr<Brush> m_brush;
    BrushType m_brushType;

    std::unique_ptr<ImplicitShape> m_Cone;
    std::unique_ptr<ImplicitShape> m_Cube;
    std::unique_ptr<ImplicitShape> m_Cylinder;
    std::unique_ptr<ImplicitShape> m_Sphere;
};

#endif // CANVAS2D_H
