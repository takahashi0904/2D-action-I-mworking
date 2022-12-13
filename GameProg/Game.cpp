#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include <math.h>

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
static int Player;
//�v���C���[
static int mx = 0;
static int my = 0;
int HP = 0;
//�G�l�~�[
static int ex;
static int ey;
static int eHP;

//�����蔻��
static float lenght = 0;
static float lenght_x = 0;
static float lenght_y = 0;


//������
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //�摜�̃��[�h
    Player = LoadGraph("�摜/Player.png");
    //�����̈ʒu������
    mx = 320;
    my = 400;
    HP = 2000;
  
    //�G�̈ʒu��������
    ex = 300;
    ey = 200;
    eHP = 1000;
}


//�X�V
void Game_Update() {

    //�ړ��t�F�[�Y
    if (CheckHitKey(KEY_INPUT_W) == 1) {//��
        my -= 3;
    }
    if (CheckHitKey(KEY_INPUT_S) == 1) {//��
        my += 3;
    }
    if (CheckHitKey(KEY_INPUT_D) == 1) {//�E
        mx += 3;
    }
    if (CheckHitKey(KEY_INPUT_A) == 1) {//��
        mx -= 3;
    }
    //

    if (mx <= ex) {
        ex--;
    }
    if (mx >= ex) {
        ex++;
    }
    if (my >= ey) {
        ey++;
    }
    if (my <= ey) {
        ey--;
    }



    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }

    //�����蔻��̌v�Z�v���O������ł����߂���������
    //Palayer�ƓG�̓����蔻��
    lenght_x = pow(mx - ex, 2);
    lenght_y = pow(my - ey, 2);
    lenght = sqrt(lenght_x + lenght_y);

    if ((20 + 20) >= lenght) {
        HP -= 1;
        eHP -= 1;
    }


    if (HP <= 0) {
        SceneMgr_ChangeScene(eScene_Over);
    }


}

//�`��
void Game_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);   // �l�p�`��`��(�h��Ԃ�)
    DrawString(0, 0, "�Q�[����ʂł��B", GetColor(0, 0, 0));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0));
    DrawRotaGraph(mx, my, 3, 0, Player, TRUE);//�w�i�̕`��
    DrawCircle(mx, my, 20, GetColor(255, 0, 0), TRUE);
    DrawCircle(ex, ey, 20, GetColor(0, 0, 255), TRUE);
    DrawFormatString(400, 280, GetColor(0, 0, 0), "Player��HP%d",HP);//������\��
    DrawFormatString(400, 300, GetColor(0, 0, 0), "Enemy��HP % d", eHP);//������\��
    DrawFormatString(mx, my, GetColor(0, 0, 0), "Player");//������\��
    DrawFormatString(ex, ey, GetColor(0, 0, 0), "Enemy");//������\��

}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}
