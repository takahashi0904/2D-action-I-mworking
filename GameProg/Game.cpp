#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include <math.h>
//#define OPLAYER 5
//#define TPLAYER 5


//�e�̔z��
//class Tama{
//public:
//  
//    int omax = OPLAYER;
//    float ox[OPLAYER];
//    float oy[OPLAYER];
//    bool of;
//
//    int tmax = TPLAYER;
//    float tx[TPLAYER];
//    float ty[TPLAYER];
//    bool tf;
//};
//Tama tama;


//1P
float ox = 0;
float oy = 0;
int oHP = 0;
//�e
int tomax;
float bullet_ox;
float bullet_oy;
bool bullet_of;


//2P
float tx = 0;
float ty = 0;
int tHP = 0;
//�e
int ttmax;
float bullet_tx;
float bullet_ty;
bool bullet_tf;


//����
static int time = 0;
static int count = 0;

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
static int py;


//�����蔻��
float otl = 0;
float otl_x = 0;
float otl_y = 0;

//�e�̓����蔻��
float ttl = 0;
float ttl_x = 0;
float ttl_y = 0;

//�摜
int bg;
int bullet;
int oPp;
int tPp;


//������
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //�摜�̃��[�h
    py = LoadGraph("�摜/Player.png");
    bg = LoadGraph("�摜/sea.png");
    bullet = LoadGraph("�摜/bullet.png");
    oPp = LoadGraph("�摜/1P.png");
    tPp = LoadGraph("�摜/2P.png");


    //�����̈ʒu������
    ox = 320;
    oy = 40;
    oHP = 100;
    
    tx = 320;
    ty = 440;
    tHP = 100;

    bullet_ox = ox;
    bullet_oy = oy;
    bullet_of = false;

    bullet_tx = tx;
    bullet_ty = ty;
    bullet_tf = false;

    ////�e�̏�����
    //for (int i = 0; i < OPLAYER; i++) {
    //    tama.ox[i] = ox;
    //    tama.oy[i] = oy;
    //    tama.of = 0;      
    //}
    //for (int i = 0; i < TPLAYER; i++) {
    //    tama.tx[i] = tx;
    //    tama.ty[i] = ty;
    //    tama.tf = 0;
    //}
}

//�X�V
void Game_Update() {

    count++;
    time = count / 100;

    if (oy < 180) {
        oy += 0.05;
        bullet_oy += 0.05;
    }
    if (ty > 300) {
        ty -= 0.05;
        bullet_ty -= 0.05;

    }

    //1P�̈ړ��ƍU��
    if (CheckHitKey(KEY_INPUT_D) == 1) {//�E
        if (ox != 620) {
            ox += 2;
            if (bullet_of == false)
                bullet_ox += 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_A) == 1) {//��
        if (ox != 20) {
            ox -= 2;
            if (bullet_of == false)
                bullet_ox -= 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_S) == 1) {//��
        bullet_of = true;
    }

    //2P�̈ړ��ƍU��
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {//�E
        if (tx != 620) {
            tx+=2;
            if (bullet_tf == false)             
                bullet_tx += 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_LEFT) == 1) {//��
        if (tx != 20) {
            tx-=2;
            if (bullet_tf == false)
            bullet_tx -= 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
        bullet_tf = true;
    }

    //1p �̒e�t���b�O
    if (bullet_of == true) {    
        bullet_oy += 5;
        if (bullet_oy > 480) {
            bullet_of = false;
            bullet_ox = ox;
            bullet_oy = oy;
        }
    }
    //2p �̒e�t���b�O
    if (bullet_tf == true) {
        bullet_ty -= 5;
        if (bullet_ty < 0) {
            bullet_tf = false;
            bullet_tx = tx;
            bullet_ty = ty;
        }     
    }


    //1p�̓����蔻��
    ttl_x = pow(bullet_tx - ox, 2);
    ttl_y = pow(bullet_ty - oy, 2);
    ttl = sqrt(ttl_x + ttl_y);
    if ((10 + 20) >= ttl) {
        oHP -= 1;
    }

    //2p�̓����蔻��
    otl_x = pow(bullet_ox - tx, 2);
    otl_y = pow(bullet_oy - ty, 2);
    otl = sqrt(otl_x + otl_y);
    if ((10 + 20) >= otl) {
        tHP -= 1;
    }
  
   
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }

    
    if (oHP <= 0) {
        SceneMgr_ChangeScene(eScene_tP);
    }

    if (tHP <= 0) {
        SceneMgr_ChangeScene(eScene_oP);
    }   
}
    

//�`��t�F�[�Y
void Game_Draw() {
    DrawRotaGraph(320, 240, 6.4, 0, bg, TRUE);//�v���C���[�̕`��

    /*DrawString(0, 0, "�Q�[����ʂł��B", GetColor(0, 0, 0));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0));*/

    //�PP�̓����蔻���`��
    DrawRotaGraph(bullet_ox, bullet_oy, 1, 0, bullet, TRUE);//1p bullet
    DrawRotaGraph(ox, oy, 2, 0, oPp, TRUE);//�v���C���[�̕`��
   // DrawCircle(ox, oy, 20, GetColor(255, 0, 0), TRUE);
    DrawFormatString(ox - 45, oy - 45, GetColor(0, 0, 0), "1P");//�v���C���[��
    DrawFormatString(ox - 45, oy - 30, GetColor(0, 0, 0), "HP%d", oHP);//HP


    //�QP�̓����蔻���`��
    DrawRotaGraph(bullet_tx, bullet_ty, 1, 0, bullet, TRUE);//2p bullet
    DrawRotaGraph(tx, ty, 2, 0, tPp, TRUE);//�v���C���[�̕`��
    //DrawCircle(tx, ty, 20, GetColor(0, 0, 255), TRUE);
    DrawFormatString(tx + 20, ty + 10, GetColor(0, 0, 0), "2P");//�v���C���[��
    DrawFormatString(tx + 20, ty + 25, GetColor(0, 0, 0), "HP % d", tHP);//HP


    //DrawFormatString(0, 100, GetColor(0, 0, 0), "�v�Z����%d�~���b", count);//������\��
    //DrawFormatString(30, 120, GetColor(0, 0, 0), "%d�b", time);//������\��
  /*  for (int i = 0; i < OPLAYER; i++) {
        DrawCircle(tama.ox[i], tama.oy[i], 10, GetColor(0, 255, 255), TRUE);
    }
    for (int i = 0; i < OPLAYER; i++) {
        DrawCircle(tama.tx[i], tama.ty[i], 10, GetColor(0, 255, 255), TRUE);
    }*/
    //�e�̕`��
    //1P
    //for (int i = 0; i < OPLAYER;i++) {
    //    DrawCircle(tama.ox[OPLAYER], tama.oy[OPLAYER], 10, GetColor(0, 255, 255), TRUE);
    //}
    ////2P
    //for (int i = 0; i < TPLAYER; i++) {
    //    DrawCircle(tama.tx[TPLAYER], tama.ty[TPLAYER], 10, GetColor(0, 255, 255), TRUE);
    //} 
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}
