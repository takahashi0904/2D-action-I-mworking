#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"



//������
void title_Initialize() {
}

//�I������
void title_Finalize() {

}

//�X�V
void title_Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Clear);//�V�[����ݒ��ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_O) != 0) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Over);//�V�[����ݒ��ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_M) != 0) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[����ݒ��ʂɕύX
    }

}

//�`��
void title_Draw() {

    DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 30, "G �Q�[���B", GetColor(255, 255, 255));
    DrawString(0, 60, "C�@�N���A�B", GetColor(255, 255,255));
    DrawString(0, 90, "O �I�[�o�[�B", GetColor(255, 255, 255));
    DrawString(0, 120, "M �Ń��j���[�B", GetColor(255, 255, 255));

}