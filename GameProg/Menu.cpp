#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"



//������
void Menu_Initialize() {

}

//�I������
void Menu_Finalize() {


}

//�X�V
void Menu_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }

}
//�`��
void Menu_Draw() {

    DrawString(200, 150, "A�@�@��", GetColor(255, 255, 255));
    DrawString(200, 200, "D�@�@�E", GetColor(255, 255,255));
    DrawString(200, 250, "S�@�@�U��", GetColor(255, 255, 255));

    DrawString(360, 150, "���@�@��", GetColor(255, 255, 255));
    DrawString(360, 200, "���@�@�E", GetColor(255, 255, 255));
    DrawString(360, 250, "���@�@�U��", GetColor(255, 255, 255));

}