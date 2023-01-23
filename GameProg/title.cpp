#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int title;    //�摜�n���h���i�[�p�ϐ�

//������
void title_Initialize() {
    title = LoadGraph("�摜/�^�C�g�����.png"); //�摜�̃��[�h
}

//�I������
void title_Finalize() {
    DeleteGraph(title);    //�摜�̉��
}

const static int GAME_Y = 330;    //�u�Q�[���v������y�ʒu
const static int MENU_Y = 360;    //�u�ݒ�v������y�ʒu
static int Flag = false;

typedef enum {
    eMenu_Game,        //�Q�[��
    eMenu_Menu,    //�ݒ�

    eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

//�X�V
void title_Update() {
    if (CheckHitKey(KEY_INPUT_DOWN) == 1 && Flag == false) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
        Flag = true;
    }
    if (CheckHitKey(KEY_INPUT_UP) == 1 && Flag == true) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
        Flag = false;
    }
    if (CheckHitKey(KEY_INPUT_S) == 1 && Flag == false) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
        Flag = true;
    }
    if (CheckHitKey(KEY_INPUT_W) == 1 && Flag == true) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
        Flag = false;
    }
    if (CheckHitKey(KEY_INPUT_O) == 1) {//��
        SceneMgr_ChangeScene(eScene_oP);//�V�[����ݒ��ʂɕύX

    }
    if (CheckHitKey(KEY_INPUT_T) == 1) {//��
        SceneMgr_ChangeScene(eScene_tP);//�V�[����ݒ��ʂɕύX

    }
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) {//�G���^�[�L�[�������ꂽ��
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMenu_Game://�Q�[���I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
            break;
        case eMenu_Menu://�ݒ�I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Menu);//�V�[����ݒ��ʂɕύX
            break;
        }
    }
}

//�`��
void title_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(0, 0, 128), TRUE);   // �l�p�`��`��(�h��Ԃ�)
    DrawBox(0, 300, 640, 480, GetColor(0, 0, 0), TRUE);   // �l�p�`��`��(�h��Ԃ�)


    DrawString(310, GAME_Y, "START", GetColor(255, 255, 255));
    DrawString(310, MENU_Y, "MENU", GetColor(255, 255, 255));
    DrawString(290, 440, "��2022", GetColor(255, 255, 255));
    DrawString(280, 460, "Takahashi", GetColor(255, 255, 255));


    DrawRotaGraph(320, 160, 4, 0, title, TRUE);//�w�i�̕`��

    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eMenu_Game://�Q�[���I�𒆂Ȃ�
        y = GAME_Y;    //�Q�[���̍��W���i�[
        break;
    case eMenu_Menu://�ݒ�I�𒆂Ȃ�
        y = MENU_Y;    //�ݒ�̍��W���i�[
        break;
    }
    DrawString(290, y, "��", GetColor(255, 255, 255));
}
