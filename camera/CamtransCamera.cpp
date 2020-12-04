/**
 * @file   CamtransCamera.cpp
 *
 * This is the perspective camera class you will need to fill in for the Camtrans lab.  See the
 * lab handout for more details.
 */

#include "CamtransCamera.h"
#include <Settings.h>
#include <math.h>
#include <iostream>

//inline float cot(float x){
//    return 1.0f/tan(x);
//}

CamtransCamera::CamtransCamera():
    m_aspectRatio(1),
    m_near(1),
    m_far(30),
    m_eye(glm::vec4(2, 2, 2, 1)),
    m_up(glm::vec4(0, 1, 0, 0)),
    m_thetaH(M_PI/3),
    m_thetaW(2*atan(m_aspectRatio*tan(0.5f*m_thetaH)))
{
    //setHeightAngle(10);
    orientLook(m_eye, glm::vec4(-2, -2, -2, 0), m_up);


    updateProjectionMatrix();
    updateViewMatrix();


    // @TODO: [CAMTRANS] Fill this in...
}

void CamtransCamera::setAspectRatio(float a)
{
    // @TODO: [CAMTRANS] Fill this in...
    m_aspectRatio = a;

    setHeightAngle(glm::degrees(m_thetaH));
    updateProjectionMatrix();

}

glm::mat4x4 CamtransCamera::getProjectionMatrix() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_perspectiveTransformation*m_scaleMatrix;
}

glm::mat4x4 CamtransCamera::getViewMatrix() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_rotationMatrix*m_translationMatrix;
}

glm::mat4x4 CamtransCamera::getScaleMatrix() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_scaleMatrix;
}

glm::mat4x4 CamtransCamera::getPerspectiveMatrix() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_perspectiveTransformation;
}

glm::vec4 CamtransCamera::getPosition() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_eye;
}

glm::vec4 CamtransCamera::getLook() const {
    // @TODO: [CAMTRANS] Fill this in...
    return -1.0f*m_w;
}

glm::vec4 CamtransCamera::getU() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_u;
}

glm::vec4 CamtransCamera::getV() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_v;
}

glm::vec4 CamtransCamera::getW() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_w;
}

glm::vec4 CamtransCamera::getUp() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_up;
}

float CamtransCamera::getAspectRatio() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_aspectRatio;
}

float CamtransCamera::getHeightAngle() const {
    // @TODO: [CAMTRANS] Fill this in...
    return m_thetaH;
}

void CamtransCamera::orientLook(const glm::vec4 &eye, const glm::vec4 &look, const glm::vec4 &up) {
    // @TODO: [CAMTRANS] Fill this in...
    m_eye = eye;
    m_up = glm::normalize(up);

    m_w = glm::normalize(-1.0f*look);

    glm::vec4 temp = m_up - (glm::dot(m_up, m_w)*m_w);
    m_v = glm::normalize(temp);

    m_u = glm::normalize(glm::vec4(glm::cross(glm::vec3(m_v.x, m_v.y, m_v.z) , glm::vec3(m_w.x, m_w.y, m_w.z)), 0));

    updateViewMatrix();
    updateProjectionMatrix();
}

void CamtransCamera::setHeightAngle(float h) {
    // @TODO: [CAMTRANS] Fill this in...
    m_thetaH = glm::radians(h);
    /* w/h = tan(thetaw/2)/tan(thetah/2)=aspectratio
     * aspectratio*tan(thetah/2)=tan(theta2/2)
     * arctan(aspectr*tan(thetah/2))*2=thetaw
     */
    m_thetaW = 2*atan(m_aspectRatio*tan(0.5f*m_thetaH));
    updateProjectionMatrix();

}

void CamtransCamera::translate(const glm::vec4 &v) {
    // @TODO: [CAMTRANS] Fill this in...
    m_eye = m_eye + v;
    updateViewMatrix();

}

void CamtransCamera::rotateU(float degrees) {
    // @TODO: [CAMTRANS] Fill this in...
    float radians = glm::radians(degrees);
    glm::vec4 u_0 = m_u;
    glm::vec4 v_0 = m_v;
    glm::vec4 w_0 = m_w;

    float sin_theta = sin(radians);
    float cos_theta = cos(radians);

    m_v = w_0*sin_theta + v_0*cos_theta;
    m_w = w_0*cos_theta - v_0*sin_theta;

    updateViewMatrix();

}

void CamtransCamera::rotateV(float degrees) {
    // @TODO: [CAMTRANS] Fill this in...
    float radians = glm::radians(degrees);
    glm::vec4 u_0 = m_u;
    glm::vec4 v_0 = m_v;
    glm::vec4 w_0 = m_w;

    float sin_theta = sin(radians);
    float cos_theta = cos(radians);

    m_u = u_0*cos_theta - w_0*sin_theta;
    m_w = w_0*cos_theta + u_0*sin_theta;

    updateViewMatrix();
}

void CamtransCamera::rotateW(float degrees) {
    // @TODO: [CAMTRANS] Fill this in...
    float radians = glm::radians(degrees);
    glm::vec4 u_0 = m_u;
    glm::vec4 v_0 = m_v;
    glm::vec4 w_0 = m_w;

    //negate
    float sin_theta = sin(-1*radians);
    float cos_theta = cos(-1*radians);

    m_u = u_0*cos_theta - v_0*sin_theta;
    m_v = v_0*cos_theta + u_0*sin_theta;

    updateViewMatrix();
}

void CamtransCamera::setClip(float nearPlane, float farPlane) {
    // @TODO: [CAMTRANS] Fill this in...
    m_near = nearPlane;
    m_far = farPlane;

    updateProjectionMatrix();

}

void CamtransCamera::updateProjectionMatrix(){
    updateScaleMatrix();
    updatePerspectiveMatrix();
}

void CamtransCamera::updateViewMatrix(){
    updateRotationMatrix();
    updateTranslationMatrix();
}

void CamtransCamera::updatePerspectiveMatrix(){
    float c = -1*(m_near/(float)m_far);
    m_perspectiveTransformation = glm::mat4(1, 0, 0, 0,
                                            0, 1, 0, 0,
                                            0, 0, -1.0f/(c+1), (float)c/(c+1),
                                            0, 0, -1, 0);
    m_perspectiveTransformation = glm::transpose(m_perspectiveTransformation);
}

void CamtransCamera::updateScaleMatrix(){
    m_scaleMatrix = glm::mat4(1.0f/(tan(0.5*m_thetaW)*m_far), 0, 0, 0,
                              0, 1.0f/(tan(0.5*m_thetaH)*m_far), 0, 0,
                              0, 0, 1.0f/m_far, 0,
                              0, 0, 0, 1);
    m_scaleMatrix = glm::transpose(m_scaleMatrix);
}

void CamtransCamera::updateRotationMatrix(){
    m_rotationMatrix = glm::mat4(m_u.x, m_u.y, m_u.z, 0,
                                 m_v.x, m_v.y, m_v.z, 0,
                                 m_w.x, m_w.y, m_w.z, 0,
                                 0, 0, 0, 1);
    m_rotationMatrix = glm::transpose(m_rotationMatrix);
}

void CamtransCamera::updateTranslationMatrix(){
    m_translationMatrix = glm::mat4(1, 0, 0, -1*m_eye.x,
                                    0, 1, 0, -1*m_eye.y,
                                    0, 0, 1, -1*m_eye.z,
                                    0, 0, 0, 1);
    m_translationMatrix = glm::transpose(m_translationMatrix);
}

